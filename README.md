# Ultrasonic Security

ชื่อโครงงาน: Ultrasonic Security<br>
ชนิดโครงงาน: Micro-controller<br>

<b>ที่มาและความสำคัญ</b><br>
  <dd>เนื่องจากปัจจุบันตามร้านค้าเกิดปัญหาเงินสูญหายอยู่บ่อยครั้งซึ่งสาเหตุอาจเกิดมาจากความหละหลวมในการดูแลรักษาความปลอดภัยของพนักงานที่อาจไม่ได้ประจำอยู่บริเวณที่เก็บเงินตลอดเวลา ส่งผลให้ร้านค้าได้รับความเสียหาย ทางกลุ่มเล็งเห็นถึงปัญหานี้ จึงได้จัดทำโครงงาน Ultrasonic Security ขึ้น
  
<b>จุดประสงค์</b><br>
  1. เพื่อเพิ่มความปลอดภัยในการดูแลเงิน
  2. เพื่อ
  
<b>ประโยชน์</b><br>
  1. ลำโพงส่งเสียงเตือนเมื่อมีคนมาเข้าใกล้บริเวณที่เก็บเงิน
  2. ลดความกังวลของผู้ประกอบการหรือพนักงานในการดูแลเงิน
  3. ลดค่าใช้จ่ายในการติดตั้งอุปกรณ์ราคาแพงเพื่อรักษาความปลอดภัย

<b>อุปกรณ์</b><br>
1. ESP 32 simulator <br>
<img src = "https://user-images.githubusercontent.com/88420671/166657183-22f6d4ba-c7f2-4973-ae8a-bf035c975bc5.png" width = "200px"><br>
2. LED <br>
<img src = "https://user-images.githubusercontent.com/88420671/166657335-da558e56-70c3-4f53-bf02-67b39a9bf3a5.png" width = "200px"><br>
3. Resistor <br>
<img src = "https://user-images.githubusercontent.com/88420671/166657359-38477cee-5dbf-4372-9ddc-a9e8da3870a4.png" width = "200px"><br>
4. HC-SR04 Ultrasonic Distance Sensor <br>
<img src = "https://user-images.githubusercontent.com/88420671/166657383-98dbf3ad-286e-4024-9c63-781665dd4e9d.png" width = "200px"><br>
5. Buzzer <br>
<img src = "https://user-images.githubusercontent.com/88420671/166657399-70d8aad2-9327-456c-8fae-c5e1e2358426.png" width = "200px"><br>
6. Slide switch <br>
<img src = "https://user-images.githubusercontent.com/88420671/166657478-f4151467-0850-471a-a4c9-4a401f309b1f.png" width = "200px"><br>


<b>หลักการทำงาน</b><br>
  <dd>เมื่อผู้ประกอบการหรือพนักงานติดธุระ หรือไม่มีเวลาในการเฝ้าเงินก็ทำการเปิดสวิตช์ให้เซนเซอร์ ultrasonic ทำงาน หากเซนเซอร์ตรวจจับได้ว่ามีคนเข้าใกล้ลิ้นชักเก็บเงิน ลำโพงก็จะส่งเสียงเตือนออกมา
  พร้อมกับมีไฟแสดง แต่หากผู้ประกอบการหรือพนักงานประจำอยู่บริเวณที่เก็บเงินก็สามารถปิดสวิตช์เพื่อไม่ให้เซนเซอร์ทำงานได้
  
<b>ข้อเสนอแนะ</b><br>
  <dd>สามารถนำไปประยุกต์เชื่อมต่อกับอินเทอร์เน็ต เพื่อส่งข้อความผ่านทางไลน์ ทำให้ทราบเวลาที่เกิดเหตุการณ์เงินสูญหายได้


