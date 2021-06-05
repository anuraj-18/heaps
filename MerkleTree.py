import hashlib

def hash256(tx_msg):
	return hashlib.sha256(tx_msg.encode()).hexdigest()

def createMerkleRoot(tx_msgs):
	merkleRoot = ""
	# tx_msg_cp = []
	l = len(tx_msgs)
	tx_hash = []
	tx_hashcp = []
	for i in range(l):
		txhash = hash256(tx_msgs[i])
		tx_hash.append(txhash)

	print(tx_hash)

	while merkleRoot == "":
		i = 0
		while i < l:
			txhash1 = tx_hash[i]
			txhash2 = ""
			i = i + 1
			if i < l:
				txhash2 = tx_hash[i]
			else:
				txhash2 = txhash1
			tx = txhash1+txhash2
			txhash12 = hash256(tx)
			tx_hashcp.append(txhash12)
			i = i + 1
		tx_hash = tx_hashcp.copy()
		tx_hashcp = []
		l = len(tx_hash)
		if len(tx_hash) == 1:
			merkleRoot = tx_hash[0]
		print(tx_hash)
	return merkleRoot

tx_msgs = ["abc", "def"]

print(createMerkleRoot(tx_msgs))
