import sys
from datetime import datetime as dt
output_file = open("run_log.txt", 'a')


class St_ampe_dOut:
    """Stamped stdout."""

    nl = True

    def write(self, x):
        """Write function overloaded."""
        if x == '\n':
            output_file.write(x)
            self.nl = True
        elif self.nl:
            output_file.write('%s> %s' % (str(dt.now()), x))
            self.nl = False
        else:
            output_file.write(x)

    def flush(var):
        pass

sys.stdout = St_ampe_dOut()

# work stuff


print('std out close')
output_file.close()