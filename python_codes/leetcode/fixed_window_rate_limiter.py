import time

class FixedWindow:
    def __init__(self, max_capacity) -> None:
        self.max_capacity = max_capacity
        
        self.current_capacity = max_capacity
        self.current_timestamp = time.time()

    def allow_request(self, packet):
        time_now = time.time()
        if (time_now - self.current_timestamp)/60 > 1.0:
            self.current_timestamp = time_now
            self.current_capacity = self.max_capacity
        
        if self.current_capacity > packet:
            self.current_capacity -= packet
            return True

        return False
