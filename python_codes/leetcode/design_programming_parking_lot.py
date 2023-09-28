class Person:
    def __init__(self, name, email, phone, address):
        self.__name = name
        self.__address = address
        self.__email = email
        self.__address = address

class Address:
    def __init__(self, house_no, road_name, district, state, country, zip_code):
        self.__house_no = house_no
        self.__road_name = road_name
        self.__district = district
        self.__state = state
        self.__country = country
        self.__zip_code = zip_code

class PaymentStatus:
    COMPLETED = 1
    FAILED = 2
    PENDING = 3
    UNPAID = 4
    REFUNDED = 5

class AccountStatus:
    ACTIVE = 1
    CLOSED = 2
    CANCELLED = 3
    BLACKLISTED = 4
    NONE = 5

from abc import ABC, abstractmethod
class ParkingSpot(ABC):
    def __init__(self, id, is_free, vehicle):
       self.__id  = id
       self.__vehicle = vehicle
       self.__is_free: bool = is_free

    @abstractmethod
    def assign_vehicle(self, vehicle):
        pass
    
    def remove_vehicle(self, vehicle):
        pass


class Compact(ParkingSpot):
    def __init__(self, id, is_free, vehicle):
        super().__init__(id, is_free, vehicle)
    
    def assign_vehicle(self, vehicle):
        return super().assign_vehicle(vehicle)

class Large(ParkingSpot):
    def __init__(self, id, is_free, vehicle):
        super().__init__(id, is_free, vehicle)
    
    def assign_vehicle(self, vehicle):
        return super().assign_vehicle(vehicle)

class MoterBike(ParkingSpot):
    def __init__(self, id, is_free, vehicle):
        super().__init__(id, is_free, vehicle)
    
    def assign_vehicle(self, vehicle):
        return super().assign_vehicle(vehicle)


class Vehicle(ABC):
    def __init__(self, license_no) -> None:
        self.__license_no = license_no
    
class Car(Vehicle):
    def __init__(self, license_no) -> None:
        super().__init__(license_no)
    
class MoterBike(Vehicle):
    def __init__(self, license_no) -> None:
        super().__init__(license_no)

class Van(Vehicle):
    def __init__(self, license_no) -> None:
        super().__init__(license_no)
    

from abc import ABC, abstractmethod
class Account(ABC):
    def __init__(self, user_name, password, person, status: AccountStatus):
        self.__user_name = user_name
        self.__password = password
        self.__person = person
        self.__status = status
    
    @abstractmethod
    def reset_password(self):
        pass


class Admin(Account):
    def __init__(self, user_name, password, person, status: AccountStatus):
        super().__init__(user_name, password, person, status)
    
    def add_parking_spot(self):
        pass
    
    def remove_parking_spot(self):
        pass

    def add_display_board(self):
        pass

    def add_exterence(self):
        pass

    def add_exit(self):
        pass
    
    def reset_password(self):
        return super().reset_password()

class ParkingAttendent(Account):
    def __init__(self, user_name, password, person, status: AccountStatus):
        super().__init__(user_name, password, person, status)

    def generate_ticket(self):
        pass

    def  reset_password(self):
        return super().reset_password()
    
    def take_monet(self):
        pass

    def process_ticket(self):
        pass

class DisplayBoard:
    def __init__(self, id, compact_spots, large_spots, moterbike_spots):
        self.__id = id
        self.__compact_spots = compact_spots
        self.__large_spots = large_spots
        self.__moterbike_spots = moterbike_spots
    
    def show_free_slots(self):
        pass

class ParkingRate:
    def __init__(self, rate, hours) -> None:
        self.__rate = rate
        self.__hours = hours
    
    def calculate_amount(self):
        pass

class Entrance:
    def __init__(self, id, ticket) -> None:
        self.__id = id
        self.__ticket = ticket

    def get_ticket(self, ticket):
        pass

class Exit:
    def __init__(self, id, ticket):
        self.__id = id
        self.__ticket = ticket
    
    def validate_ticket(self, ticket):
        pass

class ParkingLotTicket:
    def __init__(self, payment, vahicle, exit, entrance, spot):
        self.__id = id
        self.__arrival_time = time.now()
        self.__payment = payment
        self.__vahicle = vahicle
        self.__exit = exit
        self.__entrance = entrance

class Payment(ABC):
    def __init__(self, id, amount, status, timestamp) -> None:
        self.__id = id
        self.__amount = amount
        self.__status = status
        self.__timestamp = timestamp
    
    @abstractmethod
    def initiate_payment(self):
        pass

class Cash(Payment):
    def __init__(self, id, amount, status, timestamp) -> None:
        super().__init__(id, amount, status, timestamp)
    
    def initiate_payment(self):
        pass

class Card(Payment):
    def __init__(self, id, amount, status, timestamp) -> None:
        super().__init__(id, amount, status, timestamp)
    
    def initiate_payment(self):
        pass

class __ParkingLot:
    __instance = None

    def __new__(cls) -> Self:
        if cls.__instance is None:
            cls.__instance = super(__ParkingLot, cls).__new__(cls)
        return cls.__instance
        


class ParkingLot(metaclass=__ParkingLot):
    def __init__(self, id, name, address, parking_rate) -> None:
        self.__id = id
        self.__name = name
        self.__address = address
        self.__parking_rate = parking_rate
        self.__entarnce = {}
        self.__exit = {}
        self.__tickets = {}

    def add_entrance(self, entrance):
        pass

    def add_exit(self, exit):
        pass

    def is_full(self):
        pass

    def get_parking_ticket(self, vahicle):
        pass
       