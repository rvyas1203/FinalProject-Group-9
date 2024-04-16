#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// User structure
typedef struct {
    char username[50];
    char email[100];
    char password[50];
    float weight;
    float height;
    int age;
    // Additional profile information
    char gender[10];
    char fitnessGoal[50];
    char privacySettings[50];
    // Nutrition-related fields
    char dietaryPreferences[100]; // Example: Vegetarian, Low Carb, etc.
    char dietaryRestrictions[100]; // Example: Gluten-Free, Dairy-Free, etc.
    float dailyCalorieGoal; // Daily calorie intake goal
    // Social-related fields
    char friends[10][50]; // Array to store friends' usernames
    int friendCount; // Number of friends
} User;

// Fitness goal structure
typedef struct {
    char type[20];
    float target;
    char deadline[20];
    float progress; // Added progress field
} Goal;

// Workout structure
typedef struct {
    char type[20];
    int duration;
    float intensity;
} Workout;

// Nutrition structure
typedef struct {
    char food[50];
    float calories;
    float protein;
    float carbs;
    float fat;
} Nutrition;

// Social post structure
typedef struct {
    char username[50];
    char content[200];
} SocialPost;

// Challenge structure
typedef struct {
    char title[50];
    char description[200];
    char deadline[20];
    bool isActive;
    int participantCount;
} Challenge;

// Recommendation structure
typedef struct {
    char workoutRecommendation[200];
    char nutritionRecommendation[200];
} Recommendation;

// Function prototypes
User* createUser(const char username[], const char email[], const char password[], float weight, float height, int age, const char gender[], const char fitnessGoal[], const char privacySettings[], const char dietaryPreferences[], const char dietaryRestrictions[], float dailyCalorieGoal);
Goal* createGoal(const char type[], float target, const char deadline[]);
Workout* createWorkout(const char type[], int duration, float intensity);
Nutrition* createNutrition(const char food[], float calories, float protein, float carbs, float fat);
SocialPost* createSocialPost(const char username[], const char content[]);
Challenge* createChallenge(const char title[], const char description[], const char deadline[]);
Recommendation* generateRecommendations(User* user);
void displayUser(User* user);
void displayGoal(Goal* goal);
void displayWorkout(Workout* workout);
void displayNutrition(Nutrition* nutrition);
void displaySocialPost(SocialPost* post);
void displayRecommendations(Recommendation* recommendation);
void updateGoalProgress(Goal* goal, float progress);
void logWorkout(User* user, Workout* workout);
void setDietaryPreferences(User* user, const char preferences[]);
void setDietaryRestrictions(User* user, const char restrictions[]);
void setDailyCalorieGoal(User* user, float calorieGoal);
void addFriend(User* user, const char friendUsername[]);
void removeFriend(User* user, const char friendUsername[]);
void displayFriends(User* user);
void joinChallenge(User* user, Challenge* challenge);
void leaveChallenge(User* user, Challenge* challenge);

int main() {
    // Test user management
    User* user = createUser("JohnDoe", "john.doe@example.com", "password123", 70.5, 175.0, 30, "Male", "Weight Loss", "Private", "Vegetarian", "None", 2000);
    printf("User created:\n");
    displayUser(user);

    // Test goal setting and tracking
    Goal* goal = createGoal("Weight Loss", 65.0, "End of the month");
    printf("\nGoal created:\n");
    displayGoal(goal);

    // Test updating goal progress
    updateGoalProgress(goal, 50.0); // Simulate 50% progress
    printf("\nGoal progress updated:\n");
    displayGoal(goal);

    // Test workout tracking
    Workout* workout = createWorkout("Cardio", 30, 7.5);
    printf("\nWorkout created:\n");
    displayWorkout(workout);

    // Log workout for the user
    logWorkout(user, workout);
    printf("\nWorkout logged for user:\n");
    displayUser(user);

    // Set dietary preferences and restrictions
    setDietaryPreferences(user, "Low Carb, High Protein");
    setDietaryRestrictions(user, "None");
    printf("\nDietary preferences and restrictions updated:\n");
    displayUser(user);

    // Set daily calorie goal
    setDailyCalorieGoal(user, 1800);
    printf("\nDaily calorie goal updated:\n");
    displayUser(user);

    // Test social features
    SocialPost* post = createSocialPost("JohnDoe", "Just completed a great workout!");
    printf("\nSocial post created:\n");
    displaySocialPost(post);

    // Test adding friends
    addFriend(user, "Alice");
    addFriend(user, "Bob");
    printf("\nFriends added:\n");
    displayFriends(user);

    // Test removing a friend
    removeFriend(user, "Alice");
    printf("\nFriend removed:\n");
    displayFriends(user);

    // Test challenge participation
    Challenge* challenge = createChallenge("30-Day Fitness Challenge", "Join us in this exciting fitness journey!", "2024-05-01");
    joinChallenge(user, challenge);
    printf("\nUser joined the challenge:\n");
    leaveChallenge(user, challenge);
    printf("\nUser left the challenge:\n");

    // Generate personalized recommendations for the user
    Recommendation* recommendation = generateRecommendations(user);
    printf("\nPersonalized Recommendations:\n");
    displayRecommendations(recommendation);

    // Free allocated memory
    free(user);
    free(goal);
    free(workout);
    free(post);
    free(challenge);
    free(recommendation);

    return 0;
}

// Function implementations

// Create user
User* createUser(const char username[], const char email[], const char password[], float weight, float height, int age, const char gender[], const char fitnessGoal[], const char privacySettings[], const char dietaryPreferences[], const char dietaryRestrictions[], float dailyCalorieGoal) {
    User* user = (User*)malloc(sizeof(User));
    if (user == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(user->username, username);
    strcpy_s(user->email, email);
    strcpy_s(user->password, password);
    user->weight = weight;
    user->height = height;
    user->age = age;
    strcpy_s(user->gender, gender);
    strcpy_s(user->fitnessGoal, fitnessGoal);
    strcpy_s(user->privacySettings, privacySettings);
    strcpy_s(user->dietaryPreferences, dietaryPreferences);
    strcpy_s(user->dietaryRestrictions, dietaryRestrictions);
    user->dailyCalorieGoal = dailyCalorieGoal;
    user->friendCount = 0; // Initialize friend count to 0
    return user;
}

// Create fitness goal
Goal* createGoal(const char type[], float target, const char deadline[]) {
    Goal* goal = (Goal*)malloc(sizeof(Goal));
    if (goal == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(goal->type, type);
    goal->target = target;
    strcpy_s(goal->deadline, deadline);
    goal->progress = 0.0; // Initialize progress to 0%
    return goal;
}

// Update goal progress
void updateGoalProgress(Goal* goal, float progress) {
    if (progress < 0.0 || progress > 100.0) {
        printf("Invalid progress value.\n");
        return;
    }
    goal->progress = progress;
}

// Create workout
Workout* createWorkout(const char type[], int duration, float intensity) {
    Workout* workout = (Workout*)malloc(sizeof(Workout));
    if (workout == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(workout->type, type);
    workout->duration = duration;
    workout->intensity = intensity;
    return workout;
}

// Log workout for user
void logWorkout(User* user, Workout* workout) {
    // Here can implement the logic to log the workout for the user
    // For demonstration purposes, let's assume we just update the user's profile with the latest workout
    // You can extend this function to store workout history, track progress, etc.
    strcpy_s(user->fitnessGoal, "Updated Fitness Goal after workout");
}

// Set dietary preferences
void setDietaryPreferences(User* user, const char preferences[]) {
    strcpy_s(user->dietaryPreferences, preferences);
}

// Set dietary restrictions
void setDietaryRestrictions(User* user, const char restrictions[]) {
    strcpy_s(user->dietaryRestrictions, restrictions);
}

// Set daily calorie goal
void setDailyCalorieGoal(User* user, float calorieGoal) {
    user->dailyCalorieGoal = calorieGoal;
}

// Generate personalized recommendations for the user
Recommendation* generateRecommendations(User* user) {
    // Here can implement  the logic to generate personalized workout and nutrition recommendations
    // based on the user's profile, fitness goals, dietary preferences, etc.
    Recommendation* recommendation = (Recommendation*)malloc(sizeof(Recommendation));
    if (recommendation == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Simulated recommendations for demonstration
    strcpy_s(recommendation->workoutRecommendation, "Go for a 45-minute high-intensity interval training (HIIT) session.");
    strcpy_s(recommendation->nutritionRecommendation, "Try a balanced meal with lean protein, whole grains, and plenty of vegetables.");
    return recommendation;
}

// Create nutrition
Nutrition* createNutrition(const char food[], float calories, float protein, float carbs, float fat) {
    Nutrition* nutrition = (Nutrition*)malloc(sizeof(Nutrition));
    if (nutrition == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(nutrition->food, food);
    nutrition->calories = calories;
    nutrition->protein = protein;
    nutrition->carbs = carbs;
    nutrition->fat = fat;
    return nutrition;
}

// Create social post
SocialPost* createSocialPost(const char username[], const char content[]) {
    SocialPost* post = (SocialPost*)malloc(sizeof(SocialPost));
    if (post == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(post->username, username);
    strcpy_s(post->content, content);
    return post;
}

// Create challenge
Challenge* createChallenge(const char title[], const char description[], const char deadline[]) {
    Challenge* challenge = (Challenge*)malloc(sizeof(Challenge));
    if (challenge == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(challenge->title, title);
    strcpy_s(challenge->description, description);
    strcpy_s(challenge->deadline, deadline);
    challenge->isActive = true; // Challenge is active by default
    challenge->participantCount = 0; // Initialize participant count to 0
    return challenge;
}

// Add a friend to user's friend list
void addFriend(User* user, const char friendUsername[]) {
    if (user->friendCount >= 10) {
        printf("Friend limit reached.\n");
        return;
    }
    strcpy_s(user->friends[user->friendCount], friendUsername);
    user->friendCount++;
}

// Remove a friend from user's friend list
void removeFriend(User* user, const char friendUsername[]) {
    int i, j;
    for (i = 0; i < user->friendCount; i++) {
        if (strcmp(user->friends[i], friendUsername) == 0) {
            for (j = i; j < user->friendCount - 1; j++) {
                strcpy_s(user->friends[j], user->friends[j + 1]);
            }
            user->friendCount--;
            return;
        }
    }
    printf("Friend not found.\n");
}

// Display user's friends
void displayFriends(User* user) {
    printf("Friends:\n");
    for (int i = 0; i < user->friendCount; i++) {
        printf("%s\n", user->friends[i]);
    }
}

// Join a challenge
void joinChallenge(User* user, Challenge* challenge) {
    if (!challenge->isActive) {
        printf("Challenge is not active.\n");
        return;
    }
    if (challenge->participantCount >= 10) {
        printf("Challenge is full.\n");
        return;
    }
    // Add user to challenge participants
    challenge->participantCount++;
}

// Leave a challenge
void leaveChallenge(User* user, Challenge* challenge) {
    if (!challenge->isActive) {
        printf("Challenge is not active.\n");
        return;
    }
    // Remove user from challenge participants
    challenge->participantCount--;
}

// Display personalized recommendations
void displayRecommendations(Recommendation* recommendation) {
    printf("Workout Recommendation: %s\n", recommendation->workoutRecommendation);
    printf("Nutrition Recommendation: %s\n", recommendation->nutritionRecommendation);
}

// Display user details
void displayUser(User* user) {
    printf("Username: %s\n", user->username);
    printf("Email: %s\n", user->email);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f cm\n", user->height);
    printf("Age: %d\n", user->age);
    printf("Gender: %s\n", user->gender);
    printf("Fitness Goal: %s\n", user->fitnessGoal);
    printf("Privacy Settings: %s\n", user->privacySettings);
    printf("Dietary Preferences: %s\n", user->dietaryPreferences);
    printf("Dietary Restrictions: %s\n", user->dietaryRestrictions);
    printf("Daily Calorie Goal: %.2f\n", user->dailyCalorieGoal);
    printf("Friends Count: %d\n", user->friendCount);
}

// Display goal details
void displayGoal(Goal* goal) {
    printf("Type: %s\n", goal->type);
    printf("Target: %.2f\n", goal->target);
    printf("Deadline: %s\n", goal->deadline);
    printf("Progress: %.2f%%\n", goal->progress); // Include progress in display
}

// Display workout details
void displayWorkout(Workout* workout) {
    printf("Type: %s\n", workout->type);
    printf("Duration: %d minutes\n", workout->duration);
    printf("Intensity: %.2f\n", workout->intensity);
}

// Display nutrition details
void displayNutrition(Nutrition* nutrition) {
    printf("Food: %s\n", nutrition->food);
    printf("Calories: %.2f\n", nutrition->calories);
    printf("Protein: %.2f\n", nutrition->protein);
    printf("Carbs: %.2f\n", nutrition->carbs);
    printf("Fat: %.2f\n", nutrition->fat);
}

// Display social post details
void displaySocialPost(SocialPost* post) {
    printf("Username: %s\n", post->username);
    printf("Content: %s\n", post->content);
}
