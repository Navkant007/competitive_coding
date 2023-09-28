import collections

capacity_lookup = {"car": 2, "bike": 1, "truck": 4}


class Vehicle(object):
    def __init__(self, category, color, registration_id):
        self.registration_id = registration_id
        self.color = color
        self.category = category
        self.capacity = capacity_lookup[category]


class Slot(object):
    def __init__(self, row, column, category):
        self.row = row
        self.column = column
        self.category = category
        self.capacity = 4

    def set_category(self, category):
        self.category = category
        self.capacity = self.capacity[category]

    def get_category(self):
        return self.category


class Ticket(object):
    def __init__(self, ticket_id, registration_id, slot, vehicle, floor):
        self.ticket_id = str(ticket_id + 1)
        self.registration_id = registration_id
        self.slot = slot
        self.vehicle = vehicle
        self.floor = floor


class ParkingTicketSystem(object):
    def __init__(self, floors, row, slots):
        self.floors = floors
        self.slots = slots
        self.parking_plan = [(True, None)] * self.floors
        self.ticket_id = 0
        # print(f"this is parking plan --- > {self.parking_plan}")
        for floor in range(self.floors):
            self.parking_plan[floor] = [(True, None)] * row
            # print(f"this is parking plan --- > {self.parking_plan}")
            for r in range(row):
                self.parking_plan[floor][r] = [(True, None)] * self.slots

        self.slot_from_color = collections.defaultdict(list)
        self.registration_from_color = collections.defaultdict(list)
        self.slot_from_registration = collections.defaultdict(Slot)

    def get_new_ticket(self, registration_id, slot, vehicle, floor):
        ticket = Ticket(self.ticket_id, registration_id, slot, vehicle, floor)
        self.ticket_id += 1
        return ticket

    def get_nearest_slot(self, entry_point, floor, category):
        # BFS routine to find the first available slot with same category and available capacity
        # or a new parking spot. This approach will give the nearest available parking spot
        floor_plan = self.parking_plan[floor]
        print(f"floor_plan----->{floor_plan}")
        curr_x, curr_y = entry_point[0], entry_point[1]
        queue = [(curr_x, curr_y)]
        result_x, result_y = -1, -1
        curr_slot = None
        while len(queue):
            curr_len = len(queue)
            for i in range(curr_len):
                curr_x, curr_y = queue.pop(0)
                print(f"curr_x-->{curr_x} curr_y--->{curr_y}")
                print(f"floor_plan[curr_x][curr_y]---->{floor_plan[curr_x][curr_y]}")
                if floor_plan[curr_x][curr_y][0]:
                    slot = floor_plan[curr_x][curr_y][1]
                    if not slot:
                        print("No slots available at the given location (%s, %s)" % (curr_x, curr_y))
                        result_x, result_y = curr_x, curr_y
                        break
                    elif slot.category == category and slot.capacity > 0:
                        print("slot's capacity is %s at location (%s, %s)" % (slot.capacity, curr_x, curr_y))
                        result_x, result_y = curr_x, curr_y
                        curr_slot = slot
                        break
                if curr_x - 1 >= 0:
                    queue.append((curr_x - 1, curr_y))
                if curr_y - 1 >= 0:
                    queue.append((curr_x, curr_y - 1))
                if curr_y + 1 < len(floor_plan[0]):
                    queue.append((curr_x, curr_y + 1))
                if curr_x + 1 < len(floor_plan):
                    queue.append((curr_x + 1, curr_y))
            if result_x != -1:
                break
        return result_x, result_y, curr_slot

    def assign_ticket(self, vehicle, floor, entry_point):
        registration_id = vehicle.registration_id
        if registration_id in self.slot_from_registration:
            print("Vehicle with same registration already present")
            return None
        if vehicle.category not in capacity_lookup:
            print("Please check the category of the vehicle passed")
            return None
        color = vehicle.color
        row, column, slot = self.get_nearest_slot(entry_point, floor, vehicle.category)
        if not slot:
            slot = Slot(row, column, vehicle.category)
        slot.capacity -= vehicle.capacity
        if slot.capacity == 0:
            self.parking_plan[floor][row][column] = (False, slot)
        else:
            self.parking_plan[floor][row][column] = (True, slot)
        ticket = self.get_new_ticket(registration_id, slot, vehicle, floor)
        self.slot_from_color[color].append(slot)
        self.slot_from_registration[registration_id] = slot
        self.registration_from_color[color].append(registration_id)
        return ticket

    def free_ticket(self, ticket):
        if not ticket:
            print("please check the ticket passed")
        floor, slot = ticket.floor, ticket.slot
        row, column = slot.row, slot.column
        registration_id = ticket.registration_id
        slot = self.slot_from_registration[registration_id]
        if not slot:
            print("Ticket not found with the given ticket %s" % ticket.ticket_id)
            return False
        self.slot_from_registration[registration_id] = None
        self.slot_from_color[ticket.vehicle.color].remove(slot)
        self.registration_from_color[ticket.vehicle.color].remove(registration_id)
        self.parking_plan[floor][row][column] = (True, None)
        return True


def main():
    v = Vehicle("bike", "white", "34552")
    w = Vehicle("bike", "black", "22331")
    x = Vehicle("bike", "white", "34553")
    y = Vehicle("bike", "white", "34554")
    z = Vehicle("bike", "white", "34556")
    a = Vehicle("truck", "white", "34557")
    parking_system = ParkingTicketSystem(2, 2, 4)
    parking_system.assign_ticket(x, 0, (0, 0))
    parking_system.assign_ticket(y, 0, (0, 0))
    # ticket = parking_system.assign_ticket(v, 0, (0, 3))
    # parking_system.assign_ticket(w, 0, (0, 0))
    # parking_system.free_ticket(ticket)
    # parking_system.assign_ticket(z, 0, (0, 0))
    # parking_system.assign_ticket(a, 0, (0, 0))


if __name__ == "__main__":
    main()