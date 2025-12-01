#/bin/bash

# Default value
ZERO_25="0.25"
ZERO_50="0.50"
ZERO_75="0.75"
ONE="1.0"

# Default Output
OUTPUT="eDP1"

# Read Brightness actual value
brightness=$(xrandr --verbose | grep "Brightness"  | awk '{print $2}')

case $brightness in
    $ZERO_75)
        value=$ONE
        ;;

    $ZERO_50)
        value=$ZERO_75
        ;;

    $ZERO_25)
        value=$ZERO_50
        ;;
esac

# Set Brightess
if [ ! -z "$value" ]
then
    xrandr --output $OUTPUT --brightness $value
fi
