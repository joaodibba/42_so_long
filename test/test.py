
from Xlib import X, display, Xutil
char_to_xpm = {
    '1': 'WALL.xpm',
    'E': 'STAIRS.xpm',
    'P': 'FLOOR.xpm',
	'0': 'FLOOR.xpm',
	'W': 'PC_UP.xpm',
	'X': 'PC_DOWN.xpm',
	'Y': 'PC_LEFT.xpm',
	'Z': 'PC_RIGHT.xpm',
    # Add more mappings as needed
}

# Read the contents of the map file into a 2D grid
with open('map.ber', 'r') as f:
    map_data = [list(line.strip()) for line in f]

# Create a display and window using Xlib
d = display.Display()
screen = d.screen()
window = screen.root.create_window(0, 0, screen.width_in_pixels, screen.height_in_pixels, 0, screen.root_depth)

# Load the XPM images and create Xlib Pixmap objects for each one
pixmaps = {}
for filename in set(char_to_xpm.values()):
    with open(filename, 'rb') as f:
        data = f.read()
    pixmap = screen.root.create_pixmap_from_data(window, data, width=16, height=16, depth=screen.root_depth)
    pixmaps[filename] = pixmap

# Render the map data by blitting the XPM images onto the window
for y, row in enumerate(map_data):
    for x, char in enumerate(row):
        pixmap = pixmaps.get(char_to_xpm.get(char, 'unknown.xpm'), pixmaps['unknown.xpm'])
        gc = window.create_gc()
        gc.copy_area(pixmap, 0, 0, 16, 16, x * 16, y * 16)
        gc.free()

# Map the window and start the event loop
window.map()
while True:
    event = d.next_event()
    if event.type == X.DestroyNotify:
        break
