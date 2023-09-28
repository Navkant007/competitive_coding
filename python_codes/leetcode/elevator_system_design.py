class Direction:
    up = 1
    down = 1

class ElevatorState:
    IDLE = 1
    UP = 2
    DOWN = 3

class DoorState:
    OPEN = 1
    CLOSE = 2

from abc import ABC, abstractmethod

class Botton(ABC):
    def __init__(self, status):
        self.__status = status
    
    def press_down(self):
        pass

    @abstractmethod
    def is_pressed(self):
        pass

class HallBotton(Botton):
    def __init__(self, status, botton_sign):
        super().__init__(status)
        self.__botton_sign = botton_sign
    
    def is_pressed(self):
        pass

class ElevatorBotton(Botton):
    def __init__(self, status, destination_floor_number):
        super().__init__(status)
        self.__destination_floor_number = destination_floor_number
    
    def is_pressed(self):
        pass

class Panel(ABC):
    def __init__(self, id) -> None:
        self.__id = id

class HallPanel(Panel):
    def __init__(self, id, up, down) -> None:
        super().__init__(id)
        self.__up = up
        self.__down = down
    
class ElevatorPanel(Panel):
    def __init__(self, id, open, close, floor_bottons) -> None:
        super().__init__(id)
        self.open = open
        self.close = close
        self.floor_numbers = floor_bottons

class Display:
    def __init__(self, floor_number, capacity, direction) -> None:
        self.__floor_number = floor_number
        self.__capacity = capacity
        self.__direction = direction

    def show_elevator_display(self):
        pass

    def show_direction(self):
        pass

    def show_hall_display(self):
        pass

class EvevatorCar:
    def __init__(self, id, door, state, display, panel) -> None:
        self.__id = id
        self.__door = door
        self.__state = state
        self.__display = display
        self.__panel = panel
    
    def move(self):
        pass

    def stop(self):
        pass

class Door:
    def __init__(self, state):
        self.__state = state
    
    def isOpen():
        pass

class Floor:
    def __init__(self, panel, display) -> None:
        self.__panel = panel
        self.__display

class Elevator:
    def __init(self, elevator_car, location, state, building):
        self.building = building
    
    def monitoring(self):
        pass

    def dispatcher(self):
        pass

    
