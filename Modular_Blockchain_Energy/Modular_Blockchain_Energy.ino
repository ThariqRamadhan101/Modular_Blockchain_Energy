// Define State
bool AC_ON = false;
bool DC_ON = false;
bool DC_CHARGE = false;

// Define Variable
//Assume we have battery 12 Volt 100 Ah
int battery_number = 1;
long battery_capacity = 1;
long batteries_energy = 12 * 100 * battery_number * battery_capacity;
long batteries_up_lim = 14.9 * 100 * battery_number;
long batteries_down_lim = 14.4 * 100 * battery_number;
unsigned long delta_energy = 0;
// load
float load_watt = 325; //Assume we use load 325 Wh per hour
// charging
float charge_watt = 0.5; // Assume solar panel collect 0.5 Wh per hour
// time
int period = 1000; // change state every one second
unsigned long time_now = 0;
// money
unsigned long money_out = 0;
unsigned long money_in = 0;
long price = 0.791 // Assume electricty price is Rp 0.791 per Wh

void setup() {
}

void loop() {
  // TO DO: GET STATE from POST
  if (millis() >= time_now + period) {
    if (AC_ON) {
      delta_energy = load_watt * period / (3600 * 1000);
      money_out = money_out + delta_energy * price;
    }

    if (DC_ON) {
      // Energy in battery going out
      delta_energy = load_watt * period / (3600 * 1000);
      batteries_energy = batteries_energy - delta_energy;
      money_in = money_in + delta_energy * price;
    }

    if (DC_CHARGE) {
      // Energy in battery going in
      batteries_energy = batteries_energy + charge_watt * period / (3600 * 1000);
    }

    // Battery upper limit
    if (batteries_energy > batteries_up_lim) {
      batteries_energy = batteries_up_lim;
    }
    // Battery down limit
    if (batteries_energy < batteries_down_lim) {
      batteries_energy = batteries_down_lim;
    }

    battery_capacity = map(batteries_energy, batteries_down_lim, batteries_up_lim, 0, 1);

    println("##########################");
    print("STATE AC_ON : ");
    println(AC_ON);
    print("STATE DC_ON : ");
    println(DC_ON);
    print("STATE DC_CHARGE : ");
    println(DC_CHARGE);

    print("MONEY OUT : ");
    println(money_out);
    print("BATTERY ENERGY : ");
    println(battery_energy);
    print("BATTERY CAPACITY : ");
    println(battery_capacity);
    print("MONEY IN : ");
    println(money_in);
    println("##########################");
    time_now += period;
  }
}
