import threading

block_size = 3  

num_threads = 4
mapping = {
    '000': '110',
    '001': '111',
    '010': '101',
    '011': '100',
    '100': '011',
    '101': '010',
    '110': '000',
    '111': '001'
}

def to_binary(string):
    res = ''.join(format(ord(i), '08b') for i in string)
    return res

def to_string(binary):
    n = 8
    chunks = [binary[i:i+n] for i in range(0, len(binary), n)]
    
    chars = [chr(int(chunk, 2)) for chunk in chunks]
    
    return ''.join(chars)


def prepare_encryption(message):
    
    padding = block_size - (len(message) % block_size) if len(message) % block_size != 0 else 0

    message = message + '0' * padding if padding > 0 else message 
    message = list(message)
    
    size = len(message)
    chunck_size = size//num_threads
    threads = []

    for i in range(0, num_threads):
        start_index = chunck_size * i 
        end_index = chunck_size * (i+1) if i < num_threads - 1  else size 

        t = threading.Thread(target = encryption, args= (start_index, end_index, message))
        threads.append(t)
        t.start() 
    
    for i in threads:
      i.join()
    
    return "".join(message), padding

# TODO: random k-bit number to increase safety and add randomness 
def encryption(start, end, message):
    for i in range(start, end,3):
        
        if (i + block_size > end):
            block = ''.join(message[i:end])
            if (len(block) < 3):
                continue
        else:
            block = ''.join(message[i:i+block_size])
        res = list(mapping[block])

        
        for j in range(block_size):
            message[i+j] = res[j]
                                   

def decryption(message, padding):
    res, _ = prepare_encryption(message)
    return ''.join(res[:-padding -1])
    

def check_error(decrypted):
    for i in range(0,len(decrypted), 3):
        if decrypted[i:i+3] != binary[i:i+3] and i+3 < len(decrypted):
            print("Different on chunk: ", i)
            print("Original: " + binary[i] + binary[i+1] + binary[i+2])
            print("Decrypted: " + decrypted[i] + decrypted[i+1] + decrypted[i+2])

string = "Hello, how are you ? I've been doing fine, but i miss you so much. "


binary = to_binary(string);

encrypted, padding = prepare_encryption(binary)

#print(binary, encrypted, sep='\n')

decrypted = decryption(encrypted, padding)


teste = to_string(decrypted)


#print(binary, decrypted, sep='\n')


print(string,teste, sep= '\n')


