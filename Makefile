#won't change
CFLAGS = 
USER = root
GNU_PATH = $(DIR_PATH)output/host/bin/aarch64-buildroot-linux-gnu-g++
DEVICE_PATH = /etc

#will change
IP_ADDR = 10.42.0.143
DIR_PATH = /home/viny/buildroot/buildroot-2024.11/


send: final
	@echo "Process ended"
	
final: ssh_corretion wiringPi_config font_transfer
	@echo "Process ended"

ssh_corretion:
	@echo "Wrinting on SSH_config file"
	echo PermitRootLogin yes >> $(user)@$(IP_ADDR):/etc/ssh/sshd_config
	
	
	echo PasswordAuthentication yes >> $(user)@$(IP_ADDR):/etc/ssh

wiringPi_config:
	@echo "Transfering WiringPi files"
	scp $(DIR_PATH)/output/host/aarch64-buildroot-linux-gnu/sysroot/usr/lib/libwiringPi.so.3.10 $(user)@$(IP_ADDR):/usr/lib
	
	scp $(DIR_PATH)/output/host/aarch64-buildroot-linux-gnu/sysroot/usr/lib/libwiringPiDev.so.3.10 $(user)@$(IP_ADDR):/usr/lib
	
font_transfer:
	@echo "Transfering Font files"
	

