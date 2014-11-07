class Product:
	__name=""
	__stock_price=0
	__final_price=0
	def __init__(self,str1,prc,fprc):
		self.__name=str1
		self.__stock_price=prc
		self.__final_price=fprc
	def getName(self):
		return self.__name
	def getFInalPrice(self):
		return self.__final_price
	def getRetailPrice(self):
		return self.__stock_price
	def profit(self):
		return self.__final_price-self.__stock_price
class Laptop(Product):
	__disk_space=0
	__ram=0
	def __init__(self,nme,prc,fprc,dsk,rm):
		Product.__init__(self,nme,prc,fprc)
		__ram=rm
		__disk_space=dsk
class Smartphone(Product):
	__display_size=0.0
	__camera=0.0
	def __init__(self,nme,prc,fprc,dsp,cmr):
		Product.__init__(self,nme,prc,fprc)
		self.__display_size=dsp
		self.__camera=cmr
class Store:
	__prdS=[]
	__prd={}
	__name=""
	__profit=0
	def __init__(self,nm):
		self.__name=nm
	def load_new_products(self,prd,cnt):
		if(prd.getName() in self.__prd):
		 self.__prd[prd.getName()]+=cnt
		else:
		 self.__prd[prd.getName()]=cnt
		 self.__prdS.append(prd)
	def list_product(self,cls):
		total=len(self.__prdS)
		for i in range(0,total):
			if isinstance(self.__prdS[i],cls):
				print(self.__prdS[i].getName(),self.__prd[self.__prdS[i].getName()])
	def sell_product(self,prd):
		if self.__prd[prd.getName()]:
			self.__prd[prd.getName()]-=1
			self.__profit+=prd.profit()
			print("True")
		else:
			print("False")
	def total_income(self):
		return self.__profit
	def printPr(self):
		return self.__prd

def main():
	pr=Product("dada",100,200)
	lpt=Laptop("Lenovo",200,300,400,500)
	sp=Smartphone("Nexus",200,350,200,500)
	lpt1=Laptop("Lenovo2",200,350,400,500)
	st=Store("test1")
	st.load_new_products(pr,20)
	st.load_new_products(lpt,10)
	st.load_new_products(sp,2)
	st.load_new_products(pr,23)
	st.load_new_products(lpt1,10)
	st.list_product(Laptop)
	st.sell_product(sp)
	st.sell_product(sp)
	print(st.total_income())
if __name__ == '__main__':
	main()