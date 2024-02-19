#include <TFT_eSPI.h>

#define TFT_CS     5
#define TFT_RST    16
#define TFT_DC     17

#define TFT_WIDTH  320
#define TFT_HEIGHT 240

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);

// Chat GPT prompted to generate 100 words related to "S.T.E.A.M."
const char* words[] = {
    "Science", "Technology", "Engineering", "Arts", "Mathematics", "Creativity", "Innovation", "Education", "Integration", 
    "Collaboration", "Problem solving", "Design", "Experimentation", "Coding", "Robotics", "Thinking", "Exploration", 
    "Inquiry", "Discovery", "Visualization", "Logic", "Analysis", "Synthesis", "Aesthetics", "Imagination", "Architecture", 
    "Animation", "Teamwork", "Prototyping", "Modeling", "Simulation", "Computation", "Graphic design", "Music", "Theater", 
    "Dance", "Sculpture", "Painting", "Photography", "Literature", "Digital art", "Film", "Game design", "Virtual reality", 
    "A.R.", "Data analysis", "Statistics", "Probability", "Algebra", "Geometry", "Calculus", "Trigonometry", "Physics", 
    "Chemistry", "Biology", "Environment SCI", "Astronomy", "Earth science", "Ecology", "Genetics", "Nanotechnology", 
    "Biotechnology", "Renewable energy", "Sustainability", "Green tech", "Conservation", "ENGI design", 
    "Systems thinking", "Digital literacy", "Internet", "A.I.", "Machine learning", "Cybersecurity", "Big data", 
    "Cloud computing", "3D printing", "Virtual modeling", "Digital design", "Electronics", "Circuitry", "Mechanical ENGI", 
    "Aerospace ENGI", "Civil ENGI", "Chemical ENGI", "Industrial ENGI", "Material science", "Robotics ENGI", "Automation", 
    "Control systems", "H.C.I.", "Wearable tech", "Mobile app dev", "Web development", "Computer graphic", "User experience", 
    "User interface", "Game development", "Multimedia", "Ethics", "STEAM education"
};

// Array of colors for the ball
uint16_t colors[] = {TFT_BLUE, TFT_RED, TFT_GREEN, TFT_YELLOW, TFT_MAGENTA, TFT_CYAN, TFT_WHITE};

void setup() {
  Serial.begin(115200);
  delay(1000);

  tft.init();
  tft.setRotation(1);
}

void loop() {
  int numWords = sizeof(words) / sizeof(words[0]);
  int numColors = sizeof(colors) / sizeof(colors[0]);
  
  // Loop through words and colors simultaneously
  for (int i = 0; i < numWords; i++) {
    tft.fillScreen(TFT_BLACK);

    // Display "S.T.E.A.M." in green across the width of the top line of the screen
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(3);
    tft.setCursor(40, 95);
    tft.print("S.T.E.A.M.");

    // Display words or phrases relevant to "S.T.E.A.M."
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(2);
    tft.setCursor(40, 135);
    tft.print(words[i]);

    // Animation: Display a little ball with a different color that rolls across the top and bottom of the screen
    int ballX = (i % 2 == 0) ? 0 : TFT_WIDTH; // Alternates between left and right
    int ballY = (i % 2 == 0) ? 70 : 170; // Alternates between top and bottom
    int ballDirection = (i % 2 == 0) ? 1 : -1; // 1 for left to right, -1 for right to left
    int colorIndex = i / 2 % numColors; // Change color every other word
    while ((ballX >= 0) && (ballX <= TFT_WIDTH)) {
      tft.fillCircle(ballX, ballY, 10, colors[colorIndex]); // Use colorIndex to select the color
      delay(100);
      tft.fillCircle(ballX, ballY, 10, TFT_BLACK); // Erase the previous position of the ball
      ballX += ballDirection * 10; // Move the ball in the appropriate direction
    }

  }
}
