import os
import re
import shutil

cpp_pattern = re.compile(r"[qc]((?:c)?\d+)\.cpp")

c = 0
# print(os.getcwd())
for year in range(2023, 2026):
    pref = f'./{year}'
    for f in os.listdir(pref):
        m = cpp_pattern.match(f)
        if not m:
            continue
        c += 1
        # print(m.group(1))
        for prefix in "qc":
            exe_f = os.path.join(pref, f"{prefix}{m.group(1)}")
            if os.path.exists(exe_f):
                print(f'rm {exe_f}')
                os.remove(exe_f)
            dsym_f = os.path.join(pref, f"{prefix}{m.group(1)}.dSYM")
            if os.path.exists(dsym_f):
                shutil.rmtree(dsym_f)
                print(f'rm -fr {dsym_f}')
print('total', c-5)