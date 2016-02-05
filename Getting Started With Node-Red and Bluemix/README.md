# Getting Started with Node-Red and Bluemix #
<cr> 

## Overview ##
Node-RED is a tool for wiring together hardware devices, APIs and online services in new and interesting ways. Node-RED provides a browser-based flow editor that makes it easy to wire together flows using the wide range nodes in the palette. Flows can be then deployed to the runtime in a single-click. The light-weight runtime is built on Node.js, taking full advantage of its event-driven, non-blocking model. This makes it ideal to run at the edge of the network.  IBM Bluemix is a cloud platform as a service (PaaS) developed by IBM. It supports several programming languages and services as well as integrated DevOps to build, run, deploy and manage applications on the cloud. Bluemix is based on Cloud Foundry open technology and runs on SoftLayer infrastructure.

This document describes the steps to set up a Bluemix cloud connection to an Intel IoT gateway.
	
Note: this solution based on the existing [solution](https://developer.ibm.com/recipes/tutorials/connect-an-intel-iot-gateway-to-iot-foundation) published by IBM: .
	
## IMPORTANT NOTES ##
-	The Bluemix-solution currently does not support proxy (run behind firewall).  All steps below must be executed on a gateway not behind firewall.
  
## Required Hardware ##
-   Intel Internet of Things Gateway

## Assumptions ##
-   Intel Internet of Things Gateway is running version 3.1 or above
-   Node.js is installed on the Intel IoT Gateway (installed by default)
-   The Bluemix package is installed on the Intel IoT Gateway
	- You can install this package by clicking on Packages and then Add Packages from the Intel IoT Gateway Developer Hub interface
-   Node-Red is installed on the Intel IoT Gateway and is running (installed by default)


## Testing the bluemix script ##
-	Note: Currently, this example has only been tested with direct internet connections.  Ensure your gateway is connected directly to the internet.  No proxy support.
-	Open a terminal session to the Intel IoT Gateway either by a directly connected monitor or by establishing a SSH session to the IP address of the gateway	
-	Change to the /home/gwuser/bluemix-solution folder

> cd /home/gwuser/bluemix-solution
 
-	Run the ibm-iot-quickstart app.  This python app reports the CPU utilization as a MQTT topic to the MQTT broker

> python ibm-iot-quickstart.py

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
The Node-Red browser interface can be reached via
<http://ipaddressofthegateway:1880>. When it first comes up it will look
something like this.

![](http://msbreton-iotwb1.fm.intel.com/root/iotg_recipes/raw/master/Getting%20Started%20With%20Node-Red%20and%20Bluemix/images/image1.png)

- The sample Bluemix package you installed from the Intel IoT Gateway Developer Hub includes a sample Node-Red flow for communicating to Bluemix.  To import this flow, click on the 3 horizontal lines to the right of the
Deploy button and select Import, Library, and Bluemix.

- Position the imported flow on your active Sheet and click to finish the import process.

- Click on the Deploy button, top right, and Confirm deploy if needed.
- Ensure the “debug” node is turned on. The box extending to the right of the node should be solid/filled in green.
- Switch the column on the right from the Info tab to the debug tab.
- Click on the blue box to the left of the 'Run once' injector node to start the Bluemix flow.
   	
Note: No errors in the debug tab indicates that the flow is running.  There will be no other output in node-red.

## Data Visualization ##
Here's how you can see the data that is being sent from the Intel IoT Gateway to the Bluemix cloud

- Go to [https://quickstart.internetofthings.ibmcloud.com](https://quickstart.internetofthings.ibmcloud.com) with a web browser
- Enter the MAC address of your Intel IoT Gateway's internet connection
- Click 'Go'
- The page will display the chart of the gateway CPU utilization over time.

**Congratulations!  You are now successfully transmitting sensor data to/from the Bluemix cloud.**