#include"LinkQueue.cpp"
//链式队列 
bool exist(LinkQuNode *q,ElemType e)
{
	DataNode *p;
	p = q->front;
	while(p)
	{
		if(p->data == e)
		{
			return 1;
		}
		p = p->next;
	} 
	return 0;
}
int main()
{
	int a,b,c,i;
	int flag = 1; 
	ElemType e;
	LinkQuNode *q;
	DataNode *p;
	InitQueue(q);
	while(flag)
	{
		printf("请输入以下序号：\n");
		printf("*****1.排队-------输入排队病人的病历号，加入到病人排列队列中***********\n");
		printf("*****2.就诊-------病人排队队列中最前面的病人就诊，并将其从队列中删除\n");
		printf("**3、查看排队------从队首到队尾列出所有的排队病人的病历号***********\n");
		printf("*4、不再排队，余下依次就诊------从队首到队尾列出所有的排队病人的病历号，并退出运行**\n");
		printf("*******************5、下班------退出运行。**************************\n");
		scanf("%d",&a);
	switch(a)
	{
		case 1://排队 
			printf("请输入该病人的病历号：\n"); 
			while(1)
			{
				scanf("%d",&b);
				if(exist(q,b))
					{
						printf("输出的病历号重复，请重新输入:\n");
					}
					else
						break;
				
			}
			enQueue(q,b);
			break;
		case 2://就诊 
			if(QueueEmpty(q))
			{
				printf("没有排队的病人\n");
			}
			else
			{
			deQueue(q,e);
			printf("病人%d就诊\n",e);
			}
			
			break;
		case 3://查看排队 
			if(QueueEmpty(q))
			{
				printf("没有排队的病人\n");
			}
			else
			{
			p = q->front;
			printf("排队病人有：\n");
			while(p)
			{
				printf("%d ",p->data);
				p=p->next;
			}
			printf("\n");
			}
			break; 
			
		case 4://不再排队 ,余下的一次就诊 
			if(QueueEmpty(q))
			{
				printf("没有排队的病人\n");
			}
			else
			{
				printf("病人按以下次序就诊：\n");
				while(q->front)
				{
					deQueue(q,e);
					printf("%d ",e);
				}
				printf("\n");
			} 
			flag = 0;
			DestroyQueue(q);
			break;
		case 5://下班 
			if(p)
			{
				printf("请排队的病人明天就医!\n");
			}
			flag = 0;
			DestroyQueue(q);
			break;
		default:
			printf("输入不对，请重新输入\n");
			break;
	}
	}
	return 0;
}
