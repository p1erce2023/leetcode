#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
using std::array;
using std::deque;
using std::string;
using std::vector;
using std::queue;
using std::priority_queue;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::unordered_map;
using std::pair;
using std::tuple;
using std::max;
using std::min;
using std::next;
using std::distance;
using std::lower_bound;
using std::upper_bound;
using std::iota;
using std::max_element;
using std::min_element;
#define OUT(...) std::cout << __VA_ARGS__ << '\n'

using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using UMPII = unordered_map<int,int>;

struct Node {
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
};
class LFUCache {
public:
    unordered_map<int,Node*> d, fq;
    int capacity, sz;
    Node *head, *tail;

    LFUCache(int c) {
        capacity = c, sz = 0;
        head = new Node(), tail = new Node();
        head->val = tail->val = -1;
        head->next = tail, tail->prev = head;
    }

    int get(int k) {
        if (d.count(k)) {
            Node* p = d[k];
            increase_freq(p);
            return p->val;
        } else return -1;
    }

    void put(int k, int v) {
        if (d.count(k)) {
            Node* p = d[k];
            increase_freq(p);
            p->val = v;
        } else if (sz == capacity) {
            Node* to_del = tail->prev;
            extract(to_del);
            if (fq[to_del->freq] == to_del)
                fq.erase(to_del->freq);
            d.erase(to_del->key);
            delete to_del;
            insert_new(k, v);
        } else {
            insert_new(k, v);
            ++sz;
        }
    }

    void increase_freq(Node* p) {
        int f = p->freq;
        // fq
        if (fq[f] == p) {
            if (p->next == tail) {
                fq.erase(f);
            } else {
                int f_next = p->next->freq;
                if (f_next == f)
                    fq[f] = p->next;
                else
                    fq.erase(f);
            }
            if (fq.count(f+1)) {
                extract(p);
                Node *q = fq[f+1];
                insert_p_before_q(p, q);
            }
        } else {
            extract(p);
            Node *q;
            if (fq.count(f+1))
                q = fq[f+1];
            else
                q = fq[f];
            insert_p_before_q(p, q);
        }
        fq[f+1] = p;
        ++p->freq;
    }

    void insert_new(int k, int v) {
        Node* p = new Node(), *q;
        p->key = k, p->val = v, p->freq = 1;
        // insert before q
        if (fq.count(1))
            q = fq[1];
        else
            q = tail;
        insert_p_before_q(p, q);
        fq[1] = p;
        d[k] = p;
    }

    void insert_p_before_q(Node* p, Node* q) {
        q->prev->next = p;
        p->prev = q->prev;
        p->next = q;
        q->prev = p;
    }

    void extract(Node* p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LFUCache* obj = new LFUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    OUT(obj->get(1));
    obj->put(3,3);
    OUT(obj->get(2));
    OUT(obj->get(3));
    obj->put(4,4);
    OUT(obj->get(1));
    OUT(obj->get(3));
    OUT(obj->get(4));
    return 0;
}
