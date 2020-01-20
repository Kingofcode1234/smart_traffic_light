<h1> Smart traffic light</h1>
<h2>Project intro</h2>
    <p> TODO</p>
<h2>Project setup</h2>
    <ol>
        <li>Master µC, which is connected to a LCD display and a clock modul.</li>
        <li>Slave µc, which is connected to the walkers light, an Sound-Modul and an Ultasonnic sensor</li>
        <li>Slave µc, which is connected to the cars light and an Ultrasonic sensor.</li>
    </ol>
<h2>What we expect</h3>
    <ol>
    <li>The master µC will communicate with slave1 and slave2 and serves as a controll unit for the System</li>
    <li>From 6-21 the system runs normaly. So at daytime the traffic lights will switch in an regulary cycle from red to green and back.</li>
    <li>From 22-5 the system runs on night mode so it will be independend because it only has to send the message to display yellow light. </li>
    <li></li>
    </ol>


### Git basic commandos:
git pull  --> Pullen vom remote branch <br />
git status --> Aktuellen stand sehen rot wenn nicht zu git hinzugefügt. <br />
git add *|filename --> Ein File oder mehrere zu git hizufügen. <br />
git status --> Aktuellen stand sehen grün wenn zu git hinzugefügt. <br />
git commit -m "Message" --> Einene Commit erstellen zum pushen danach. <br />
git push --> Aktuellen commit zu remote pushen. <br />

### Codes 
0) Ask Slave if someone is near the traffic light --> 1 yes -- 0 no 
1) Blink Green
2) Switch to Green Traffic Light
3) Switch to Yellow Traffic Light
4) Switch to Red Traffic Light
5) Check if Someone is near the Traffic Light master --> slave request 
6) Yes someone is near the Traffic Light // TODO delete
7) Night Mode -- night mode

## Sources 
https://www.avrfreaks.net/forum/atmega32-interfacing-spi
https://www.aeq-web.com/atmega328-4bit-16x2-lcd-display-amtel-studio-c/?lang=en


