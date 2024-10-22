import json
import getpass
from cryptography.fernet import Fernet
import os

# Δημιουργία κλειδιού κρυπτογράφησης
def generate_key():
    key = Fernet.generate_key()
    with open("secret.key", "wb") as key_file:
        key_file.write(key)

# Φόρτωση του κλειδιού
def load_key():
    return open("secret.key", "rb").read()

# Κρυπτογράφηση
def encrypt_password(password):
    key = load_key()
    f = Fernet(key)
    encrypted_password = f.encrypt(password.encode())
    return encrypted_password

# Αποθήκευση κωδικών
def save_password(username, password):
    encrypted_password = encrypt_password(password)
    
    # Έλεγχος αν το αρχείο passwords.json υπάρχει, αλλιώς δημιουργία
    if not os.path.exists("passwords.json"):
        with open("passwords.json", "w") as file:
            json.dump({}, file)  # Δημιουργεί ένα κενό JSON αντικείμενο
    
    with open("passwords.json", "r+") as file:
        data = json.load(file)
        data[username] = encrypted_password.decode()
        file.seek(0)
        json.dump(data, file, indent=4)

# Κύριο πρόγραμμα
if __name__ == "__main__":
    generate_key()  # Ενεργοποίησε αυτή τη γραμμή μόνο μία φορά για να δημιουργήσεις το κλειδί
    username = input("Δώσε όνομα χρήστη: ")
    #password = input("Δώσε κωδικό: ") Σβήσε το σχόλιο αν θες να εμφανίζεται ο κωδικός
    password = getpass.getpass("Δώσε κωδικό: ")
    save_password(username, password)
    print("Ο κωδικός αποθηκεύτηκε με ασφάλεια.")
