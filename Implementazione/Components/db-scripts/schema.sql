-- Connessione al database
\c :dbname

-- Creazione della tabella Light
CREATE TABLE IF NOT EXISTS Light (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(20) NOT NULL,
    color VARCHAR(20) NOT NULL,
    intensity INT NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
);

-- Creazione della tabella Camera
CREATE TABLE IF NOT EXISTS Camera (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(20) NOT NULL,
    recording INT NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
);

-- Creazione della tabella Conditioner
CREATE TABLE IF NOT EXISTS Conditioner (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(20) NOT NULL,
    temperature INT NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
);

-- Creazione della tabella Device
CREATE TABLE IF NOT EXISTS Device (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(20) NOT NULL,
    nome VARCHAR(20) NOT NULL,
    inizio INT NOT NULL,
    fine INT NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
);

-- Creazione della tabella Sensor
CREATE TABLE IF NOT EXISTS Sensor (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(15) NOT NULL,
    movement INT NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
);

-- Creazione della tabella SensorGarden
CREATE TABLE IF NOT EXISTS SensorGarden (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(15) NOT NULL,
    temperature INT NOT NULL,
    humidity INT NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
);

CREATE TABLE IF NOT EXISTS LogDb (
    comp varchar(25)NOT NULL,
    state VARCHAR(25) NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (temp)
);

CREATE TABLE IF NOT EXISTS Garden (
    t INT NOT NULL,
    id INT NOT NULL,
    temperature INT NOT NULL,
    humidity INT NOT NULL,
    descr VARCHAR(30) NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t)
);

CREATE TABLE IF NOT EXISTS Irrigator (
    t INT NOT NULL,
    id INT NOT NULL,
    stato VARCHAR(20) NOT NULL,
    pressure VARCHAR(20) NOT NULL,
    pid INT NOT NULL,
    temp VARCHAR(25) NOT NULL,
    PRIMARY KEY (t, pid)
)