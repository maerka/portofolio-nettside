#include <utility>
#include <iostream>
template<class T>


class SimpleSet{
    public:
        /** Construct empty set **/
        SimpleSet(){
			currentSize = 0;
			maxSize = 0;
			data = new T[maxSize];
			//data = nullptr;
		}


        /** Destructor */
		~SimpleSet() {
			delete [] data;
			data = nullptr;
		}


        /** Insert i into set, return true if the element was inserted, else false **/
		bool insert(T i) {
			if (exists(i)) { //sjekker om i er i settet. I så fall legges IKKE i til og derfor returneres false
				return false;
			}
			else {
				if (currentSize == maxSize) {
					resize(currentSize + 10);
				}
				data[currentSize] = i;
				currentSize++;
				return true;
			}
		}
        
		
		/** Returns true if i is in the set **/
		bool exists(T i) {
			for (int k = 0; k < currentSize; k++) {
				//cout << "IT'S ALIVE 1" << endl;
				if (data[k] == i) {
					//cout << "IT'S ALIVE 2" << endl;
					return true;
				}
			}
			//cout << "IT'S ALIVE 3" << endl;
			return false;
		}


        /** Removes i from the set, return true if an element was removed **/
		bool remove(T i) {
			int position = find(i);
			if (position >= 0) { //siste betingelse fordi det ikke er poeng i bytte hvis den er på rett plass
				if (position != currentSize - 1) {
					std::swap(data[position], data[currentSize - 1]);
				}
				currentSize--;
				return true;
			}
			return false;
		}


		// Overlaster << operator
		friend ostream& operator << (ostream& os, const SimpleSet<T>& set) {
			for (int i = 0; i < set.currentSize; i++) {
				os << set.data[i] << "\t";
			}
			os << endl;
			return os;
		}

    private:
        /** Dynamic array containing set elements **/
        T *data;
        /** Current number of elements **/
        int currentSize;

        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. Returnerer -1 hvis ikke i liste**/
		int find(int i) {
			for (int k = 0; k < currentSize; k++) {
				if (data[k] == i) {
					return k;
				}
			}
			return -1;
		}
        /** Resizes data, superflous elements are dropped. **/
		void resize(int n) {
			maxSize = n;
			T *tempData = new T[n];
			if (n<currentSize) {
				currentSize = n;
			}
			for (int k = 0; k < currentSize; k++) {
				tempData[k] = data[k];
			}
			delete[] data;
			data = tempData;
		}
};
