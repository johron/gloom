import glob, os, shutil
from progressbar import ProgressBar

def generate_original(source, target, filename): 
    renamed_file = filename.replace(source, target)
    renamed_file = renamed_file.replace(' - ', '_') 
    renamed_file = renamed_file.replace(' ', '_') 
    renamed_file = renamed_file.lower() 
    target_dir = os.path.dirname(renamed_file)
    if not os.path.exists(target_dir):
        os.makedirs(target_dir)
    shutil.copyfile(filename, renamed_file) 
    
progress_bar = ProgressBar()
source_dir = "Creator Pack V2"
target_dir = "original"
source_files = glob.glob(source_dir + '/**/*.*', recursive=True)

for filename in progress_bar(source_files):
    generate_original(source_dir, target_dir, filename)

print("-- Imported "  + str(len(source_files)) + " files from " + source_dir)
