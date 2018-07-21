from progressbar import ProgressBar
from PIL import Image
import glob

def optimize_image(filename):
    image = Image.open(filename)
    image.save(filename, optimize=True)
    return ""

original_files = glob.glob('original/**/*.png', recursive=True) + glob.glob('original/**/*.jpg', recursive=True)
progrss_bar = ProgressBar()

print("-- Optimizing originals")
for filename in progrss_bar(original_files):
    optimize_image(filename)