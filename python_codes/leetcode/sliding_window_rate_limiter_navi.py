import time


class SlidingWindowRateLimiter:
    def __init__(self, max_capacity, time_unit = None) -> None:
        self.time_unit = 60 or time_unit
        self.max_capacity = max_capacity
        self.current_capacity = 0
        self.current_timestamp = time.time()
        self.prev_capacity = max_capacity
    
    def allow_request(self, packet):
        time_now = time.time()
        if (time_now - self.current_timestamp) > self.time_unit:
            self.current_timestamp = time_now
            self.prev_capacity = self.current_capacity
            self.current_capacity = 0
        
        current_counter = (self.prev_capacity * (self.time_unit - (time_now - self.current_timestamp) // self.time_unit )) + packet

        if current_counter > self.max_capacity:
            return False
        return True

    