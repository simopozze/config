WALP_DIR=~/Pictures/Walps/*.jpg
feh --bg-fill $(find $WALP_DIR -type f | shuf -n 1)
