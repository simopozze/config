while true; do
	xsetroot -name " [$(date +"%k:%M:%S")] [$(date +"%d/%m/%y")] [storage: $(df /dev/sda4 | grep / | awk '{print $5}')]"    
	sleep 1s
done &
