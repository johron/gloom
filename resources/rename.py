import glob
import os

def rename_file(filename):
    result = filename.replace(' - ', '_')
    result = result.replace(' ', '_')
    result = result.lower()
    os.rename(filename, result)

    print(result)


for filename in glob.iglob('**/*', recursive=True):
    rename_file(filename)
