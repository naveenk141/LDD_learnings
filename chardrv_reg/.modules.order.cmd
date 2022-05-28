cmd_/home/naveen/Desktop/chardrv/modules.order := {   echo /home/naveen/Desktop/chardrv/mymodule.ko; :; } | awk '!x[$$0]++' - > /home/naveen/Desktop/chardrv/modules.order
