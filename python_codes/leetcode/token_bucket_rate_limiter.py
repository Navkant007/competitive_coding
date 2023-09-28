import time

class TokenBucket:
    def __init__(self, max_tokens, refill_rate) -> None:
        self._max_tokens = max_tokens
        self.refill_rate = refill_rate
        self.current_tokens = max_tokens
        self.current_timestamp = time.time()
    
    def allow_request(self, tokens):
        self.refill()
        if self.current_tokens > tokens:
            self.current_token -= tokens
            return True
        
        return False

    
    def refill(self):
        time_now = time.time()
        token_to_add = (time_now - self.current_timestamp) * self.refill_rate

        self.current_tokens = min(self._max_tokens, self.current_tokens + token_to_add)
        self.current_timestamp = time_now