import os
import re
import shutil

cpp_pattern = re.compile("[qc]((?:c)?\d+)\.cpp")

c = 0
for f in os.listdir():
    m = cpp_pattern.match(f)
    if not m:
        continue
    c += 1
    # print(m.group(1))
    for prefix in "qc":
        exe_f = f"{prefix}{m.group(1)}"
        if os.path.exists(exe_f):
            os.remove(exe_f)
        dsym_f = f"{prefix}{m.group(1)}.dSYM"
        if os.path.exists(dsym_f):
            shutil.rmtree(dsym_f)
print('total', c-5)