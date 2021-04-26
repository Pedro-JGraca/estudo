import sqlite3
from sqlite3.dbapi2 import Cursor



class devices: #add tratamento para quando não acha ID
    def __init__(self,name='',auth=0,pending=1):
        self.conn = sqlite3.connect('devices.db')
        self.cursor = self.conn.cursor()
        self.name = name
        self.auth = auth
        self.pending = pending

    def inserirDevice(self,device):
        if(type( device ) == devices):
            dados = [device.name,device.auth,device.pending]
            self.cursor.executemany("""
            INSERT INTO devices (nome, auth,pending)
            VALUES (?,?,?)
            """, dados)
            return True
        else:
            return False
            
    def lerDevice(self,id):
        retorno = ""
        if(type( id ) == int):
            self.cursor.execute("""
            SELECT * FROM devices WHERE id = ?
            """, (id))

            
            for linha in self.cursor.fetchall():
                retorno += linha + "\n"


            return True, retorno
        else:
            return False, retorno
        
    def alterarDevice(self,id,device):
        if(type( id ) == int) and (type( device ) == devices):
            self.cursor.execute("""
            UPDATE devices
            set nome = ?, auth = ?, pending = ?
            where id = ? 
            """, (device.name,device.auth,device.pending,id))
            self.conn.commit()

            return True
        else:
            return False
    
    def removerDevice(self,id):
        if(type( id ) == int):
            self.cursor.execute("""
            DELETE FROM clientes
            WHERE id = ?
            """, (id))
            return True
        return False;

    def listarDevices(self):
        self.cursor.execute("""
        SELECT COUNT(*) FROM Cadastro
        """)
        numero = 0
        for linha in self.cursor.fetchall():
            numero = int(linha)

        index = 0
        while (index < numero):
            self.lerDevice(index)
            index+=1
            return True
        return False;

    def __del__(self):
        self.conn.close()

class logs:
    def __init__(self,idDevice,entrou,direcao,momento):
        self.conn = sqlite3.connect('devices.db')
        self.cursor = self.conn.cursor()
        self.idDevice = idDevice
        self.entrou = entrou
        self.direcao = direcao
        self.momento = momento


def carregarDevices():
    listDevice = []


    return listDevice