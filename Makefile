# Nombre del compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -fopenmp `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

# Nombre del archivo fuente y del ejecutable
SRC = faceDetection.cpp
TARGET = faceDetection

# Carpeta donde se guardan las imágenes recortadas
CROPPED_DIR = croppedFaces

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

cleanfaces:
	rm -f $(CROPPED_DIR)/*


clean: cleanfaces
	rm -f $(TARGET)
	