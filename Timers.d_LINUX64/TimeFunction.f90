
module TimeFunctionData

!	Define time function
	type TimeFunction
		real(8) :: time		! Time
		real(8) :: value	! Value of function
	end type TimeFunction

	integer :: LenTMFunction = 0	! Number of points defining the time function
	type(TimeFunction), allocatable :: TMFunction(:)

contains 

	real function CurrentTMFunction(T)
	implicit none
	real(8), intent(in) :: T

	integer :: i
	real(8) :: f1, f2, T1, T2

	CurrentTMFunction = 0.0

	do i = 1, LenTMFunction
		T1 = TMFunction(i)%time
		if (T.ge.T1) then
			if (i .eq. LenTMFunction) then	!  Out of bound
				write(*,100) T, TMFunction(i)%time
100				format(" ***Error*** Current time is out of time function ! " / &
					   "    Current time = ", 1p, e10.3, /  &
					   "    End time of the time function = ", e10.3 )
				stop
			end if

			T2 = TMFunction(i+1)%time
			if (T.le.T2) then
				f1 = TMFunction(i)%value
				f2 = TMFunction(i+1)%value
				CurrentTMFunction = f1 + (f2-f1)*(T-T1)/(T2-T1)
			endif
		end if
	end do

	end function CurrentTMFunction

end module TimeFunctionData
