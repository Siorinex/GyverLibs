// пример управления системной частотой
// мы можем только уменьшить (разделить) системную частоту (на платах ардуино 16 МГц)
// Пониженная частота позволяет чуть снизить потребление или питать МК от пониженного напряжения!
#include <GyverPower.h>

// с понижением частоты "уйдут" функции времени
// для их коррекции можно сделать так:
#define millis() (millis() << (CLKPR & 0xF))
#define micros() (micros() << (CLKPR & 0xF))
#define delay(x) delay((x) >> (CLKPR & 0xf))
#define delayMicroseconds(x) delayMicroseconds((x) >> (CLKPR & 0xf))

// данные дефайны нужно прописать ПЕРЕД подключением остальных библиотек.
// Таким образом дефайн сможет "проникнуть" в библиотеку и скорректировать 
// работу используемых там функций времени

void setup() {
  power.setSystemPrescaler(PRESCALER_16); 	// замедляем в 16 раз
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, !digitalRead(13)); // мигаем
  delay(1000);    // держит 1 секунду, несмотря на пониженный клок!
}