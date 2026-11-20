#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// ========================
//       USER CLASS
// ========================
class User {
private:
    string username;
    string password;
    string phoneNumber;
    string status;
    string lastSeen;
    
public:
    User() {
        // TODO: Implement default constructor
    }
    
    User(string uname, string pwd, string phone) {
        // TODO: Implement parameterized constructor
    }
    
    string getUsername() const {
        // TODO: Implement getter
        return "";
    }
    
    string getPhoneNumber() const {
        // TODO: Implement getter
        return "";
    }
    
    string getStatus() const {
        // TODO: Implement getter
        return "";
    }
    
    string getLastSeen() const {
        // TODO: Implement getter
        return "";
    }
    
    void setStatus(string newStatus) {
        // TODO: Implement setter
    }
    
    void setPhoneNumber(string phone) {
        // TODO: Implement setter
    }
    
    void updateLastSeen() {
        // TODO: Implement last seen update
    }
    
    bool checkPassword(string pwd) const {
        // TODO: Implement password check
        return false;
    }
    
    void changePassword(string newPwd) {
        // TODO: Implement password change
    }
};

// ========================
//      MESSAGE CLASS
// ========================
class Message {
private:
    string sender;
    string content;
    string timestamp;
    string status;
    Message* replyTo;
    
public:
    Message() {
		sender = "";
		content = "";
		timestamp = "";
		status = "";
		replyTo = nullptr;
    }
    
    Message(string sndr, string cntnt) {
		sender = sndr;
		content = cntnt;
		status = "Sent";
		replyTo = nullptr;
		updateTimestamp();
    }
    
    string getContent() const {
        
		return content; 
    }
    
    string getSender() const {
       
		return sender;
    }
    
    string getTimestamp() const {
        
        return timestamp;
    }
    
    string getStatus() const {
        
        return status;
    }
    
    Message* getReplyTo() const {
        
        return replyTo;
    }
    
    void setStatus(string newStatus) {
		status = newStatus;
    }
    
    void setReplyTo(Message* msg) {
		replyTo = msg;
    }
    
    void updateTimestamp() {
		time_t now = time(0);
		string currentTime = ctime(&now);

		if (!currentTime.empty() && currentTime.back() == '\n') {
			currentTime.pop_back(); 
		}
		timestamp = currentTime;
    }
    
    void display() const {
        cout << "\nSender: " << sender;
        cout << "\nTimestamp: " << timestamp;
        cout << "\nStatus: " << status;
		cout << "\nMessage: " << content;

		if (replyTo != nullptr) {
			cout << "\nReplying to: " << replyTo->getContent();
		}
		cout << endl;
    }
    
    void addEmoji(string emojiCode) {
		string emoji;

		if (emojiCode == ":)") emoji = "😊";
		else if (emojiCode == ":(") emoji = "😢";
		else if (emojiCode == ":D") emoji = "😄";
		else if (emojiCode == ";)") emoji = "😉";
		else if (emojiCode == "<3") emoji = "❤️";
		else if (emojiCode == ":P") emoji = "😛";
		else {
			cout << "Invalid emoji code!" << endl;
			return;
		}
    }
};

// ========================
//       CHAT CLASS (BASE)
// ========================
class Chat {
protected:
    vector<string> participants;
    vector<Message> messages;
    string chatName;
    
public:
    Chat() {
        // TODO: Implement default constructor
    }
    
    Chat(vector<string> users, string name) {
        // TODO: Implement parameterized constructor
    }
    
    void addMessage(const Message& msg) {
        // TODO: Implement message addition
    }
    
    bool deleteMessage(int index, const string& username) {
        // TODO: Implement message deletion
        return false;
    }
    
    virtual void displayChat() const {
        // TODO: Implement chat display
    }
    
    vector<Message> searchMessages(string keyword) const {
        // TODO: Implement message search
        return {};
    }
    
    void exportToFile(const string& filename) const {
        // TODO: Implement export to file
    }
};

// ========================
//     PRIVATE CHAT CLASS
// ========================
class PrivateChat : public Chat {
private:
    string user1;
    string user2;
    
public:
    PrivateChat(string u1, string u2) {
        // TODO: Implement constructor
    }
    
    void displayChat() const override {
        // TODO: Implement private chat display
    }
    
    void showTypingIndicator(const string& username) const {
        // TODO: Implement typing indicator
    }
};

// ========================
//      GROUP CHAT CLASS
// ========================
class GroupChat : public Chat {
private:
    vector<string> admins;
    string description;
    
public:
    GroupChat(vector<string> users, string name, string creator) {
        // TODO: Implement constructor
    }
    
    void addAdmin(string newAdmin) {
        // TODO: Implement add admin
    }
    
    bool removeParticipant(const string& admin, const string& userToRemove) {
        // TODO: Implement remove participant
        return false;
    }
    
    bool isAdmin(string username) const {
        // TODO: Implement admin check
        return false;
    }
    
    bool isParticipant(string username) const {
        // TODO: Implement participant check
        return false;
    }
    
    void setDescription(string desc) {
        // TODO: Implement set description
    }
    
    void displayChat() const override {
        // TODO: Implement group chat display
    }
    
    void sendJoinRequest(const string& username) {
        // TODO: Implement join request
    }
};

// ========================
//    WHATSAPP APP CLASS
// ========================
class WhatsApp {
private:
    vector<User> users;
    vector<Chat*> chats;
    int currentUserIndex;
    
    int findUserIndex(string username) const {
        for(int i = 0; i < users.size(); i++) {
            if(users[i].getUsername() == username) {
                return i;
            }
        }
        return -1;
    }
    
    bool isLoggedIn() const {
        if(currentUserIndex != -1) return true;
        return false;
		// return currentUserIndex != -1;
    }
    
    string getCurrentUsername() const {
        if (isLoggedIn()) {
            return users[currentUserIndex].getUsername();
        }
        return "";
    }
    
public:
    WhatsApp() : currentUserIndex(-1) {}
    
    void signUp() {
        cout << "Enter username: ";
        string uname;
        cin >> uname;

        if (findUserIndex(uname) != -1) {
            cout << "Rejected! Username already exists.\n";
            return;
        }

        cout << "Enter password (at least 6 characters): ";
        string pwd;
        cin >> pwd;

        if (pwd.length() < 6) {
            cout << "Rejected! Password must be at least 6 characters long.\n";
            return;
        }

        cout << "Enter phone number: ";
        string phone;
        cin >> phone;

        users.push_back(User(uname, pwd, phone));
        cout << "Sign up successful!\n";
    }
    
    void login() {
        cout << "Enter username: ";
        string uname;
        cin >> uname;

        cout << "Enter password: ";
        string pwd;
        cin >> pwd;

        int idx = findUserIndex(uname);
        if (idx == -1 || !users[idx].checkPassword(pwd)) {
            cout << "Authentication failed! Invalid username or password.\n";
            return;
        }

        currentUserIndex = idx;
        users[currentUserIndex].setStatus("Online");
        users[currentUserIndex].updateLastSeen();
        cout << "Login successful! Welcome back, " << uname << ".\n";
    }
    
    void startPrivateChat() {
        cout << "Enter recipient username: ";
        string otherUser;
        cin >> otherUser;

        if (otherUser == getCurrentUsername()) {
            cout << "Error: You cannot start a private chat with yourself.\n";
            return;
        }

        int otherIdx = findUserIndex(otherUser);
        if (otherIdx == -1) {
            cout << "Error: User '" << otherUser << "' not found.\n";
            return;
        }
		
		PrivateChat* newChat = new PrivateChat(getCurrentUsername(), otherUser);
        chats.push_back(newChat);
        users[currentUserIndex].updateLastSeen();
        cout << "Private chat created successfully with " << otherUser << "!\n";
    }
    
    void createGroup() {
        // TODO: Implement group creation
    }
    
    void viewChats() const {
        // TODO: Implement chat viewing
    }
    
    void logout() {
        users[currentUserIndex].setStatus("Offline");
		users[currentUserIndex].updateLastSeen();
		currentUserIndex = -1;
		cout << "Logged out successfully.\n";
    }
    
    void run() {
        while (true) {
            if (!isLoggedIn()) {
                cout << "\n1. Login\n2. Sign Up\n3. Exit\nChoice: ";
                int choice;
                cin >> choice;
                
                if (choice == 1) login();
                else if (choice == 2) signUp();
                else if (choice == 3) break;
            }
            else {
                cout << "\n1. Start Private Chat\n2. Create Group\n3. View Chats\n4. Logout\nChoice: ";
                int choice;
                cin >> choice;
                
                if (choice == 1) startPrivateChat();
                else if (choice == 2) createGroup();
                else if (choice == 3) viewChats();
                else if (choice == 4) logout();
            }
        }
    }
};

// ========================
//          MAIN
// ========================
int main() {
    WhatsApp whatsapp;
    whatsapp.run();
    return 0;
}