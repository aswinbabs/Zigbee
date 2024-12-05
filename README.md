# XBee Serial Communication with LED Control  

---

## 🚀 Project Overview  

This project demonstrates serial communication between two systems using XBee modules and Arduino microcontrollers.  
- Two XBee modules are configured using **Digi XCTU** software and connected to separate systems.  
- Each XBee communicates wirelessly, sending data via the Arduino Serial Monitor.  
- Commands sent through one system's Serial Monitor control the LED connected to the Arduino on the other system.

---

## ⚙️ Features  

- Wireless communication using two XBee modules.  
- LED control based on commands sent from another system:  
  - `'1'`: LED ON  
  - `'0'`: LED OFF  
- Real-time data transmission and feedback on the Serial Monitor.  

---

## 🔧 Hardware Setup  

### Components:  
- 2 Arduino boards (e.g., Uno)  
- 2 XBee modules (Series 1 or 2)  
- 2 USB cables for Arduino  
- Digi XCTU software for XBee configuration  
- 1 LED  
- 1 Resistor (220 ohms)  
- Jumper wires  

### Connections:  
1. **XBee Module**:  
   - Connect XBee TX → Arduino RX.  
   - Connect XBee RX → Arduino TX.  
   - Ensure a common ground between the XBee and Arduino.  

2. **LED**:  
   - Anode (+ve) → Arduino Pin 13.  
   - Cathode (-ve) → Ground via a 220-ohm resistor.  

---

## 🔧 XBee Configuration  

1. Open **Digi XCTU**.  
2. Connect and detect your XBee modules.  
3. Configure both XBee modules:  
   - **XBee 1** (Coordinator): Set a unique PAN ID and baud rate of 9600.  
   - **XBee 2** (Router): Match the PAN ID and baud rate of XBee 1.  
4. Test the communication between the XBee modules in XCTU.  

---

## 📜 Code  

```cpp
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(13, OUTPUT); // Set pin 13 as output for LED
  delay(1000);         // Wait for connections to stabilize
}

void loop() {
  if (Serial.available()) {
    char incomingData = Serial.read();  // Read data
    Serial.println(incomingData);       // Echo data
    if (incomingData == '1') {
      digitalWrite(13, HIGH);           // LED ON
    } else if (incomingData == '0') {
      digitalWrite(13, LOW);            // LED OFF
    }
  }
}
