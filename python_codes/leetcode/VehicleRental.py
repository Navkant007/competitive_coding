"""
Features:
Rental service have multiple branches throughout the city. Assume one city for now.
Each branch has limited number of different kinds of vehicles.
Each vehicle can be booked with predefined price. For simplicity, assume fixed pricing.
Each vehicle can be booked in multiples of 1 hour slot each. (For simplicity, assume  slots of  booking lie within a single day)
No past bookings should be allowed.
"""


"""
vehicle
branch
VechicleRentleService
    add_branch
    add_vehicle
    rent_vehicle
    get_available_vehicles
    print_system_view
"""

from collections import defaultdict

class Vehicle:
    def __init__(self, registration_id, vehicle_type, hourly_pricing) -> None:
        self.registration_id = registration_id
        self.vehicle_type = vehicle_type
        self.hourly_pricing = hourly_pricing
        self.booking_status = False
        self.booking_start = None
        self.booking_end = None

class VehicleBranch:
    def __init__(self, branch_id, branch_name) -> None:
        self.branch_id = branch_id
        self.branch_name = branch_name
        self.vehicle_data = defaultdict(Vehicle)
        self.vehicles = defaultdict(list)
    
    def add_vehicle(self, vehicle):
        self.vehicle_data[vehicle.registration_id] = vehicle
        self.vehicles[vehicle.type].append(vehicle)

#this is a sigleton class
class VehicleRentingSystem:
    def __init__(self, id, city) -> None:
        self.id = id
        self.city = city
        self.branch_id = 0
        self.vehicle_id = 0

        self.branches = {}
        self.booked_vehicle = {}
        self.available_vehicle = {}
    
    def add_branch(self, branch_name: str, vehicle_data: list):
        branch = VehicleBranch(self.branch_id, branch_name)
        for vehicle in vehicle_data:
            vehicle_obj = Vehicle(self.vehicle_id, vehicle[0], vehicle[1])
            branch.add_vehicle(vehicle_obj)
            # self.available_vehicle[]
            self.vehicle_id += 1
        self.branch[branch.branch_id] = branch 
        self.branch_id += 1

    def add_vehicle(self, branch_id, vehicle):
        vehicle_obj = Vehicle(self.vehicle_id, vehicle[0], vehicle[1])
        self.branch[branch_id].add_vechile(vehicle_obj)
        self.vehicle_id += 1
    
    def rent_vehicle(self, vehicle_type, start_hour, end_hour):
        pass

    def display_dashboad(self):
        pass

if __name__ == "__main__":
    pass

