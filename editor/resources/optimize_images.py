from progressbar import ProgressBar
import glob, subprocess

def optimize_image(filename):
    subprocess.call("pngcrush_1_8_11_w64 -ow -rem allb -reduce -q "+ filename)

original_files = glob.glob('thumbnails/**/*.png', recursive=True)
progrss_bar = ProgressBar()

print("-- Optimizing thumbnails")
for filename in progrss_bar(original_files):
    optimize_image(filename)