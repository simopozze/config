#
#BAR LAUNCHER


# Icons
CLOCK_ICON=""
DATE_ICON=""
DISK_ICON=""
BATTERY_ICON=""
VOLUME_ICON=""
BRIGHTNESS_ICON=""

while true; do

	CLOCK="$CLOCK_ICON $(date +"%H:%M:%S")"
	DATE="$DATE_ICON $(date +"%d/%m/%y")"
	DISK="$DISK_ICON $(df /dev/nvme0n1p4 | grep / | awk '{print $5}')"
    
	bat_value=$(acpi -b | awk '{print $4}')
	BATTERY="$BATTERY_ICON $(echo $bat_value | sed 's/,//g')"

	vol_value=$(pactl get-sink-volume $(pactl get-default-sink) | awk '{print $5}')
	VOLUME="$VOLUME_ICON $vol_value"

	BRIGHTNESS="$BRIGHTNESS_ICON $(xrandr --verbose | grep Brightness | awk '{print $2}')"

	xsetroot -solid "#6272a4" -name " $CLOCK - $DATE $DISK" 
	sleep 1
done &
