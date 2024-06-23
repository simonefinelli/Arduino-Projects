/**
 * The program compute the average luminosity registered by the 
 * photoreistor every 50ms (sampling with a buffer of 100).
 */

// config photoresisto
#define PHOTORESISTOR_PIN A0
// config sampling
#define LUMINOSITY_SAMPLES 100
int luminosity_buffer[LUMINOSITY_SAMPLES] = {0};
int idx = 0;
unsigned long last_time_read_luminosity = millis();
unsigned long sampling_delay = 50;  // [ms]

void setup() {
  // init serial communication
  Serial.begin(115200);
}

void loop() {
  unsigned long time_now = millis();
  if (time_now - last_time_read_luminosity > sampling_delay) {
    if (idx == LUMINOSITY_SAMPLES) {
      idx = 0;
      pretty_print_luminosity();
    }
    luminosity_buffer[idx] = analogRead(PHOTORESISTOR_PIN);
    idx++;
    Serial.print(".");

    last_time_read_luminosity += sampling_delay;
  }
}

void pretty_print_luminosity()
{
  int average = compute_avg();
  Serial.println("");
  Serial.print("The AVG luminosity is " + String(average));
  Serial.println("");
}

int compute_avg()
{
  long sum = 0;
  for (int i = 0; i < LUMINOSITY_SAMPLES; i++) {
    sum += luminosity_buffer[i];
  }
  return sum / LUMINOSITY_SAMPLES;
}

