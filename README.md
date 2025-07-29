Flight Management System: User Guide for Ticket Attendants of Fly-by-Night Airlines

Welcome to the Flight Management System! This guide will teach you how to use this console-based application, helping you manage flight details, seat reservations, and passenger information.

---Getting Started---

To begin, the system will present you with the Main Menu. All interactions will be performed by typing a number corresponding to your desired action and pressing Enter. After most actions, you will be prompted to "Press Enter to continue..." before returning to the menu. 

---Main Menu Overview---

The Main Menu is allows for general flight management tasks:

    1. Add Flight: Create a new flight in the system.
    2. List Flights: View all active flights currently in the system.
    3. Check, Book or Cancel Ticket(s): Enter a specific flight's menu to handle seat reservations.
    4. Cancel Flight: Remove an entire flight from the system, which also cancels all associated reservations.
    5. Print Passenger Manifest: Displays passenger details for a selected flight.
    6. Exit: Close the application.

---Detailed Operations---

1. Add Flight

To add a new flight:

    Select 1 from the Main Menu.
    The system will prompt you to "Please input the flight number:". Enter a unique flight number (e.g., YP17) and press Enter.
    If the flight number is unique, the flight will be added. If the number already exists, you'll receive a message indicating so, and the flight won't be added.

2. List Flights

To view active flights:

    Select 2 from the Main Menu.
    The system will display a list of all flights currently in the system, along with their flight numbers. This helps you keep track of all scheduled flights.

3. Check, Book or Cancel Ticket(s) (Accessing the Flight Seat Reservation Menu)

This option allows you to manage individual seat reservations for a specific flight.

    Select 3 from the Main Menu.

    You will be asked to "Please input the flight number:" for the flight you wish to manage. Enter the flight number and press Enter.

    If the flight number is valid, you will enter the Flight Seat Reservation Menu:

        1. View Seat Status:
            Select 1 from the Flight Seat Reservation Menu.
            The system will display the status of each seat (1 through 10) on the selected flight. It will show if the seat is "Available" or "Reserved". If reserved, it will also display the passenger's name, phone, and email (if provided).

        2. Reserve a Seat:
            Select 2 from the Flight Seat Reservation Menu.
            You will be asked to "Enter seat number (1-10):".
            If the seat is already reserved, you'll be notified. Otherwise, you'll be prompted to enter the customer's details:
                Name: (e.g., Down Hog)
                Phone: (e.g., 102-017-1428)
                Email: (optional, press Enter if not available)
                Address: (optional, press Enter if not available)
            Once all details are entered, the system will confirm if the seat was reserved successfully.

        3. Cancel a Reservation (by Seat Number):
            Select 3 from the Flight Seat Reservation Menu.
            Enter the seat number (1-10) of the reservation you wish to cancel.
            The system will confirm if the reservation was canceled or if no reservation was found for that seat.

        4. Cancel by Name:
            Select 4 from the Flight Seat Reservation Menu.
            Enter the customer's exact name.
            If a reservation matching the name is found and canceled, you'll receive a confirmation. If multiple passengers have the same name, this option will only cancel the first reservation found for that name.

        5. Cancel by Phone Number:
            Select 5 from the Flight Seat Reservation Menu.
            Enter the customer's exact phone number.
            The system will confirm if a reservation matching the phone number was canceled. Similar to canceling by name, this will cancel the first reservation found for that phone number.

        6. Back to Main Menu:
            Select 6 to return to the main application menu.

4. Cancel Flight

This action permanently removes a flight from the system.

    Select 4 from the Main Menu.
    You will be prompted to "Please input flight number:" Enter the flight number you wish to cancel.
    Important: Before the flight is deleted, the system will list all reserved passengers on that flight and their contact information. This is to ensure you have a record for contacting them about their canceled reservation.
    After the passenger list, the flight will be removed from the system. If the flight number doesn't exist, you'll be informed.

5. Print Passenger Manifest

This option generates a list of passengers for a specific flight.

    Select 5 from the Main Menu.
    You will be prompted to "Please input the flight number:" for which you want the manifest.
    If the flight is found, the system will print two versions of the passenger manifest:
        By Seat Number: Passengers are listed by seat numbers in ascending order, along with their contact information.
        Alphabetical: Passengers are listed alphabetically by their names, along with their contact information.

---Notes---

	When you are prompted to "Press Enter to continue...", and you press enter, the program "clears" the console by filling the console with some empty lines. At the top of the main.cpp file, you may change the number of lines outputted by changing the number that the variable clearLines is set to.
	Case Sensitivity: When entering names, phone numbers, or flight numbers for searching or canceling, ensure you use the exact case and spelling as originally entered.
	
This guide should provide you with a comprehensive understanding of the Flight Management System. If you have any further questions, please refer to the relevant ICS4U student. Thank you for consuming the fruits of Mr. Hudson's ICS4U classes' labour!
