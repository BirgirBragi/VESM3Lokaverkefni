# Leikurinn Pong á 64x64 rgb Matrix skjá

### Fyrsta Tilraun
---

#### Heimildir, Íhlutir o.fl.

íhlutir notaðir:

- Raspberry Pi Zero
- PowerBoost 1000C
- 64x64 rgb Matrix Skjár
- Adafruit rgb Matrix Bonnet
- DC power adapter
- SPDT Slide Switch
- 3 Lithium Batteries

Tutorials sem stuðst var við

- https://learn.adafruit.com/matrix-led-sand
- https://howchoo.com/pi/raspberry-pi-led-matrix-panel

Upprunalega Hugmyndin:
 
Að nota joystick með ESP32 til þess að stýra Pong tölvuleik á rgb matrix skjá. Hægt væri síðan að birta high score sem gert væri yfir netið

---

#### Uppsetning

Fyrst var Adafruit rbg Matrix Bonnet sett ofan á Rasperry Pi Zero-inn og rafmagnið tengt frá Bonnetinu yfir í skjáinn með snúru. Einnig var red ribbon snúra tengd við Bonnetið og skjáinn

![ alt text for screen readers](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211207_081806.jpg "Text to show on mouseover")

Síðan var pinni 4 lóðaður við pinna 18 á Bonnetinu

![ alt text for screen readers](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211207_081852.jpg "Text to show on mouseover")

Síðan var SPDT Slide Switch lóðaður við ground á PowerBoost 1000C til þess að geta auðveldlega slökkt á rafmagninu.

![ alt text for screen readers](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211207_081916.jpg "Text to show on mouseover")

og snúrur tengdar á milli PowerBoost og Bonnetsins. Við það var DC power adapterinn notaður

![ alt text for screen readers](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211207_081953.jpg "Text to show on mouseover")

Síðan var ekkert annað eftir heldur en að tengja batteríin í PowerBoostinn og við það fékk Bonnetinn, Raspberry Pi Zero-inn og matrix skjárinn rafmagn

![ alt text for screen readers](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211207_082053.jpg "Text to show on mouseover")

---

#### Kóði

Að uppsetningunni lokinni var tími til þess að fá Matrix skjáinn til þess að virka með einföldu "Hello World!" dæmi. En til þess þurfti library fyrir raspberry pi

Heill fjagra klukkutíma tími í skólanum (þar sem kennari var ekki við) fór í það að prófa ýmis library og kóða til þess að fá skjáinn til þess að virka en alltaf fór eitthvað úrskeiðis með þessi blessuðu library. Við endurræstum raspberry pi, installuðum nýju OS, eyddum út öðrum libraryum sem gætu truflað, pössuðum vel upp á það að uppsetningin væri rétt en kjarninn á vandamálinu virtist ekki hafa neitt með okkur að gera. Vegna þess að þegar við installuðum [þessu](https://github.com/hzeller/rpi-rgb-led-matrix.git) library eftir hzeller af github fengum við error skilaboð sem gaf til kynna að það hreinlega vantaði sumar skrár í libraryinu. Þannig við kíktum örsnöggt í library möppuna og fundum allar möppur frá github libraryinu á sínum stað, en þær voru allar tómar. Gögn sem hefðu átt að installast með þegar við slógum inn "git clone https://github.com/hzeller/rpi-rgb-led-matrix.git" hreinlega voru ekki þarna.

Vegna ótal villumeldinga sem við fengum þrátt fyrir að hafa fylgt nákvæmlega leiðbeiningum og gert tilraunir með okkar eigin þekkingu bara til þess að fá skjáinn til þess að "virka". Þá ákváðum við að það væri best að skipta yfir í annan skjá til þess að geta skilað einhverju. Vegna þess að nú voru tveir fjagra klukkutíma tímar búnir og við höfðum einungis lokið við uppsetninguna. Næsta tilraun var því smá breyting á verkefninu, en í henni fólst að í staðinn fyrir rbg Matrix skjáinn þá var OLED notaður.

---

### Önnur Tilraun

---

#### Heimildir, Íhlutir o.fl.

íhlutir notaðir:
- ESP32
- Joystick
- OLED

Tutorials sem stuðst var við:

- [https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/](https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/)
- [https://lastminuteengineers.com/joystick-interfacing-arduino-processing/](https://lastminuteengineers.com/joystick-interfacing-arduino-processing/)

Upprunaleg hugmynd:
Að nota Joystick með ESP32 til þess að stýra Pong tölvuleik á OLED skjá. Hægt væri síðan að birta high score sem gert væri yfir neti. 

---

#### Uppsettning

Fyrst tengdum við Esp32 við Joystick og fengum analog gildi. Ákváðum bara að nota eina átt, JoyX (s.s. upp og niður) til þess að stýra leikmaninnum í Pong.
Kóði: [https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Code/EspJoystick.ino](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Code/EspJoystick.ino)

![](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211208_214809.jpg)

Svo tengdum við ESP32 við OLED og við gætum látið OLED skjáinn virka. Með kóða sem fundinn er í adafruit library-i

![](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211208_214757.jpg)

Síðan tókum við Pong kóða fyrir OLED og betrumbættum til þess að hægt væri að nota joystick 
Pong kóði notaður = [https://github.com/eholk/Arduino-Pong](https://github.com/eholk/Arduino-Pong)

![](https://github.com/BirgirBragi/VESM3Lokaverkefni/blob/main/Myndir/IMG_20211208_215101.jpg)

Eitt vandamál sem við lentum í var að eftir að við tengdum ESP32 við Adafruit IO feed þá byrjaði það að hökta rosalega mikið. Eftir nokkrar tilraunir við að laga þetta var það enn að hökta en reyndar ekki eins mikið. 
