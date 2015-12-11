#### 
#### README.MD

	This document describes the steps to set up a Bluemix cloud connection to an Intel IoT gateway.
	
	Note: this solution based on the existed solution: https://developer.ibm.com/recipes/tutorials/connect-an-intel-iot-gateway-to-iot-foundation/
	
	ver 1.1  - 12/09/2015 - nnm
	Update README to changes in the release package
	
	ver 1.0  - 11/23/2015 - nnm
	Release
	
##### IMPORTANT NOTES
	
* The Bluemix-solution currently does not support proxy (run behind firewall).  All steps below must be executed on  
  a gateway not behind firewall.
  
##### SETUP

* First, on the target, create a folder called 'bluemix-solution', under /home/gwuser 

* download the zip file from the 'developer.ibm.com' link above and copy the zip to the target /home/gwuser

	$ scp ibm-iot-quickstart.zip root@<gw-ip-addr>:/home/gwuser/
	
* unzip the zip file to bluemix-solution
	
	$ cd /home/gwuser
	
	$ unzip ibm-iot-quickstart.zip -d /home/gwuser/bluemix-solution	
	
##### RUN APP
	
* run the ibm-iot-quickstart app
	- This python app reports the CPU utilization as a MQTT topic to the MQTT broker
	
	$ cd bluemix-solution/samples
	$ python ibm-iot-quickstart.py

	```
	client.py ibm-iot-quickstart.py
	root@WR-IntelligentDevice:/home/gwuser/bluemix-solution/samples# python ibm-iot-quickstart.py 
	No config file found, connecting to the Quickstart service
	MAC address: 000bab8b0a86
	0.0
	message published
	87.7922077922
	message published
	88.3376849434
	message published

	```
	leave it running or press Ctrl+C to terminate the app 

* Run node-RED app

	$ ./node-red
	
	- Open a web browser @ http://<gw-ipaddr>:1880
	- Import the 'node-RED-Bluemix-Flow.txt
	- Deploy the flow, and click on the 'Run once' injector node to start the Bluemix flow.
   	
	  note: no error indicates that the flow is running	

##### DATA VISUALIZATION

* Open a browser @QuickStart and enter the device MAC address to see the MQTT bluemix-solution topic
	- open 'https://quickstart.internetofthings.ibmcloud.com'
	- Enter the MAC address report previously  - click 'Go'
	- The page will display the chart of the gateway CPU utilization over time.	

##### eof
