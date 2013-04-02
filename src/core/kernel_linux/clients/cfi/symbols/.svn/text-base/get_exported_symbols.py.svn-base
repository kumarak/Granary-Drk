
import pickle

if __name__ == "__main__":
    syms = set()
    with open("/dev/get_symbols", "r") as f:
        for sym in f:
            syms.add(sym.rstrip("\n"))
    
    with open("exported_syms", "wb") as f:
        pickle.dump(syms, f)
