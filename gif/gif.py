import imageio
import os

# Folder where the images are located
folder_path = '.'

# Filename pattern of the PPM images
filename_pattern = 'out{}.ppm'

# Output GIF file name
output_gif = 'animation.gif'

# Number of images
num_images = 33948

# Total duration in seconds for the GIF to loop once
total_duration = 60  # in seconds

# Calculate duration each frame should be displayed
frame_duration = total_duration / num_images

# Create a list of file paths sorted by number
image_files = [os.path.join(folder_path, filename_pattern.format(i)) for i in range(1, num_images + 1)]

# Create a GIF animation
with imageio.get_writer(output_gif, mode='I', duration=frame_duration) as writer:
    for filename in image_files:
        image = imageio.imread(filename)
        writer.append_data(image)

print("GIF created successfully!")

