# Getting Started with Node-Red and Bluemix #
<cr>

## Overview ##

This document describes the steps to set up a Bluemix cloud connection to an Intel IoT gateway.
	
Note: this solution based on the existed solution: https://developer.ibm.com/recipes/tutorials/connect-an-intel-iot-gateway-to-iot-foundation.
	
## IMPORTANT NOTES ##
	
* The Bluemix-solution currently does not support proxy (run behind firewall).  All steps below must be executed on  
  a gateway not behind firewall.
  
## Required Hardware ##

-   Intel Internet of Things Gateway


## Assumptions ##


-   Intel Internet of Things Gateway is running version 3.1 or above

-   Node.js is installed on the Intel IoT Gateway (installed by default)

-   The Bluemix package is installed on the Intel IoT Gateway
	- You can install this package by clicking on Packages and then Add Packages from the Intel IoT Gateway Developer Hub interface

-   Node-Red is installed on the Intel IoT Gateway and is running (installed by default)


## Testing the bluemix script ##
	
-	Note: Currently, this example has only been tested with direct internet connections.  Ensure your gateway is conneted directly to the internet.  No proxy support.
-	Log on to the Intel IoT Gateway	
-	cd /home/gwuser/bluemix-solution
-	Run the ibm-iot-quickstart app.  This python app reports the CPU utilization as a MQTT topic to the MQTT broker
	-	python ibm-iot-quickstart.py
-	You should see output like this

```

	No config file found, connecting to the Quickstart service
	MAC address: 000bab8b0a86
	0.0
	message published
	87.7922077922
	message published
	88.3376849434
	message published

```

-	Press Ctrl+C to terminate the app 

## Run node-RED example flow ##

- Open a web browser @ http://<gw-ipaddr>:1880
- Import the 'node-RED-Bluemix-Flow.txt from the library 
- Deploy the flow, and click on the 'Run once' injector node to start the Bluemix flow.
   	
Note: No error indicates that the flow is running.  There will be no other output in node-red.  No debug output.

## Data Visualization ##
Here's how you can see the data that is being sent from the Intel IoT Gateway to the Bluemix cloud

- Go to 'https://quickstart.internetofthings.ibmcloud.com' with a web browser
- Enter the MAC address of your Intel IoT Gateway's internet connection
- Click 'Go'
- The page will display the chart of the gateway CPU utilization over time.
