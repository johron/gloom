from PIL import Image
from progressbar import ProgressBar
import os, glob, sys

def create_thumbnail(path, size):
    file, ext = os.path.splitext(path)
    image = Image.open(path)
    image.thumbnail(size)
    thumbnail = file.replace("original", "thumbnails") + ext
    target_dir = os.path.dirname(thumbnail)
    if not os.path.exists(target_dir):
        os.makedirs(target_dir)
    image.save(thumbnail, optimize=True)


all_files = glob.glob('original/**/*.png', recursive=True) + glob.glob('original/**/*.jpg', recursive=True)
progrss_bar = ProgressBar()

for filename in progrss_bar(all_files):
    create_thumbnail(filename, (128, 128))

print("-- Generated "  + str(len(all_files)) + " thumbnails")