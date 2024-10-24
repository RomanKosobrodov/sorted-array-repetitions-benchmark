import argparse
import scipy.stats as stats
import numpy as np
import matplotlib.pyplot as plt


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Plot benchmark results")
    parser.add_argument("data",
                        help="CSV file with benchmark results",
                        type=str)
    args = parser.parse_args()
    x = np.genfromtxt(args.data, delimiter=",")

    start = 4
    nx = np.log10(x[start:-1, 0])
    ny = np.log10(x[start:-1, 1])
    result = stats.linregress(nx, ny)
    xx = np.arange(x[start-1, 0], x[-1, 0], 100)
    yy = 10**(result.intercept + np.log10(xx) * result.slope)
    print(f"{10**result.intercept:.3f} * x ^ {result.slope:.3f}")

    nx = np.log10(x[1:, 0])
    ny = x[1:, 2]
    result1 = stats.linregress(nx, ny)
    xx1 = np.arange(x[2, 0]*0.75, x[-1, 0], 1)
    yy1 = result1.intercept + np.log10(xx1) * result1.slope
    print(f"{result1.intercept:.3f} + {result1.slope:.3f} * log10(x)")

    plt.figure(num="Execution time")
    plt.loglog(x[:, 0], x[:, 1], "k-", label="na"+chr(239)+"ve")
    plt.loglog(x[:, 0], x[:, 2], "r-", label="optimal")
    plt.loglog(xx, yy, "k:", label="O(n)")
    plt.loglog(xx1, yy1, "r:", label="O(log n)")

    plt.xlabel("number of elements")
    plt.ylabel("execution time, ns")
    plt.legend(frameon=False)
    plt.savefig("execution-time.png", dpi=300)

    xx1 = xx1[70:]
    rr = (result1.intercept + np.log10(xx1) * result1.slope) / 10**(result.intercept + np.log10(xx1) * result.slope)
    plt.figure(num="speed-up")
    plt.semilogx(x[:, 0], x[:, 2]/x[:, 1], "k-", label="measured")
    plt.semilogx(xx1, rr, "k:", label="simulated")
    plt.semilogx(x[:, 0], np.ones_like(x[:, 0]), color=(0.5,0.5,0.5,0.5), linewidth=1)
    plt.xlabel("number of elements")
    plt.ylabel("speed-up (na"+chr(239)+"ve / optimal)")
    plt.legend(frameon=False)
    plt.savefig("speed-up.png", dpi=300)

    plt.show()