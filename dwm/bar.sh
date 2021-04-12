while true; do
	xsetroot -name "$(date +"%k:%M:%S")   $(date +"%d/%m/%y")   $(df /dev/sda4 | grep / | awk '{print $5}')   $(amixer get Master | awk -F'[][]' 'END{ print $4":"$2 }') "    
	sleep 1s
done &
