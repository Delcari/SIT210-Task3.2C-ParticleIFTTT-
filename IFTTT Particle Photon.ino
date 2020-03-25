int soilMoisturePin = A0;
void setup() {
    pinMode(soilMoisturePin, INPUT);
}

bool moist;
int soilReading;

bool isMoist(bool moist)
{
    //sensor light reading
    soilReading = analogRead(soilMoisturePin)/10;
    
    
    //Particle.publish("Moisture Percentage", String(soilReading));
    if (soilReading > 50)
    {
        if(moist == false)
        {
            Particle.publish("Moist", "true");
            return true;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(moist == true)
        {
            Particle.publish("Moist", "false");
            return false;
        }
        else
        {
            return false;
        }
    }
}

void loop() {
    delay(100);
    
    moist = isMoist(moist);
}
