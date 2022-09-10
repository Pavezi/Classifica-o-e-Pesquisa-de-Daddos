class Hash:

     def __init__(self,tam):
          self.tab = {}
          self.tam_max = tam

     def fhash(self, chave):
          v = int(chave)
          return v%self.tam_max

     def full(self):
          return len(self.tab) == self.tam_max

     def show(self):
          for i in self.tab:
               print("Hash[%d] = " %i, end="")
               print (self.tab[i])

     def clear(self, chave):
          pos = self.search(chave)
          if pos != -1:
               del self.tab[pos]
               print("-> Dado da posicao %d apagado" %pos) 
          else:
               print("Item nao encontrado")

     def search(self, chave):
          pos = self.fhash(chave)
          if self.tab.get(pos) == None: # se esta posição não existe
               return -1 #saida imediata
          if self.tab[pos] == chave: 
               return pos
          return -1

     def put(self, item):
          if self.full():
               print("-> ATENÇÃO Tabela Hash CHEIA")
               return
          pos = self.fhash(item)
          if self.tab.get(pos) == None: # se posicao vazia
               self.tab[pos] = item
               print("-> Inserido HASH[%d]" %pos)
          else:
            while(pos+1) > size:
              next = pos+1
              if self.tab.get(next) == None: # se posicao vazia
               self.tab[next] = item
               print("-> Inserido HASH[%d]" %pos)
              else: # se posicao ocupada
               print("-> Ocorreu uma colisao na posicao %d" %pos)             
# fim Classe Hashlinear

size = 7
tab = Hash(size)

print("\n****************************************************")
print("      Tabela HASH Sem Colisões (%d itens) " %size)
print("****************************************************")
for i in range (0,size,1):
     print("\nInserindo %d" %(i + 1));
     item = input(" - Digite um valor : ")
     tab.put(item)
item = input("\n - Digite um valor para buscar: ")
pos = tab.search(item)
if pos == -1:
     print("Não encontrado")
else:
     print("Encontrado na posição: ", pos)
item = input("\n - Digite  um valor para apagar: ")
tab.clear(item)
print("\nImprimindo")
tab.show()
print("\n")
