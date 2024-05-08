import pandas as pd
import os, sys
import matplotlib.pyplot as plt
breadprice = pd.read_csv(os.path.join(sys.path[0], 'breadprice.csv'), index_col=0, header=0)
breadprice = breadprice.fillna(0)
means_per_year = breadprice.mean(axis=1, skipna=True, numeric_only=True)
plt.plot(means_per_year)
plt.show()