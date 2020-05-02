pathstr='floats.bin'
with open(pathstr) as f:
    content = f.readlines()[2:]
    f.seek(0)
    f.writelines(content)
    print(f.truncate()) # truncate and deprecate the rest