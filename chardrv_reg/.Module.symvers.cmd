cmd_/home/naveen/Desktop/chardrv/Module.symvers := sed 's/\.ko$$/\.o/' /home/naveen/Desktop/chardrv/modules.order | scripts/mod/modpost  -a  -o /home/naveen/Desktop/chardrv/Module.symvers -e -i Module.symvers   -T -