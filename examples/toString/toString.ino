#include <RTClib.h>
#include <WireNoFreeze.h>

RTC_DS1307 rtc;

void setup() {
  while (!Serial)
    ;  // for Leonardo/Micro/Zero

  Serial.begin(57600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1)
      ;
  }  // end rtc.begin()

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop() {
  DateTime now = rtc.now();

  // buffer can be defined using following combinations:
  // hh - the hour with a leading zero (00 to 23)
  // mm - the minute with a leading zero (00 to 59)
  // ss - the whole second with a leading zero where applicable (00 to 59)
  // YYYY - the year as four digit number
  // YY - the year as two digit number (00-99)
  // MM - the month as number with a leading zero (01-12)
  // MMM - the abbreviated English month name ('Jan' to 'Dec')
  // DD - the day as number with a leading zero (01 to 31)
  // DDD - the abbreviated English day name ('Mon' to 'Sun')

  char buf1[] = "hh:mm";
  Serial.println(now.toString(buf1));

  char buf2[] = "YYMMDD-hh:mm:ss";
  Serial.println(now.toString(buf2));

  char buf3[] = "Today is DDD, MMM DD YYYY";
  Serial.println(now.toString(buf3));

  char buf4[] = "MM-DD-YYYY";
  Serial.println(now.toString(buf4));

  delay(1000);
}
