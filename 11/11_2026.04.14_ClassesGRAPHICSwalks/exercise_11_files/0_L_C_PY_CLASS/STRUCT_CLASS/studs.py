class stud:
  def __init__(self,name,course,points):
    self.NAM=name
    self.COURSE=course
    self.POINTS=points
  

group=[ ]
group.append( stud('John Smith','PHYS291',55))
group.append( stud('Eve Taylor','I100',85)  )
print(group[0].NAM,group[0].COURSE)
print(group[1].NAM,group[1].COURSE)

